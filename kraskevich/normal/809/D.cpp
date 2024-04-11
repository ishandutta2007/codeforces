#include <bits/stdc++.h>    
using namespace std;

template<typename V, typename F, typename A>
struct Node {
    A add{};
    V val{};
    F func{};
    int size{1};
    int prior;
    Node* L{nullptr};
    Node* R{nullptr};

    Node(V v): val(v), func(v), prior(rand()) {}
};

template<typename V, typename F, typename A, class AA, class FA, class VA, class FF>
struct TreapUtils {
    AA add2add;
    FA func2add;
    VA val2add;
    FF func2func;
    using NodeT = Node<V, F, A>;
    
    TreapUtils(const AA& aa, const FA& fa, const VA& va, const FF& ff):
        add2add(aa), func2add(fa), val2add(va), func2func(ff) {}


    void push(NodeT* t) {
        if (!t)
            return;
        if (t->L)
            t->L->add = add2add(t->L->add, t->add);
        if (t->R)
            t->R->add = add2add(t->R->add, t->add);
        t->func = func2add(t->func, t->add);
        t->val = val2add(t->val, t->add);
        t->add = {};
    }

    void recalc(NodeT* t) {
        if (!t)
            return;
        t->size = 1;
        t->func = t->val;
        push(t->L);
        push(t->R);
        if (t->L) {
            t->size += t->L->size;
            t->func = func2func(t->func, t->L->func);
        }
        if (t->R) {
            t->size += t->R->size;
            t->func = func2func(t->func, t->R->func);
        }
    }

    NodeT* merge(NodeT* L, NodeT* R) {
        push(L);
        push(R);
        if (!L)
            return R;
        if (!R)
            return L;
        if (L->prior > R->prior) {
            L->R = merge(L->R, R);
            recalc(L);
            return L;
        }
        R->L = merge(L, R->L);
        recalc(R);
        return R;
    }

    template<class P, typename K>
    pair<NodeT*, NodeT*> split(NodeT* t, K key, P stay_right) {
        push(t);
        if (!t)
            return {nullptr, nullptr};
        pair<NodeT*, NodeT*> res;
        if (stay_right(t, key)) {
            auto c = split(t->L, key, stay_right);
            t->L = c.second;
            res = {c.first, t};
        } else {
            auto c = split(t->R, key, stay_right);
            t->R = c.first;
            res = {t, c.second};
        }
        recalc(t);
        return res;
    }
};

template<typename V, typename F, typename A>
const auto SIZE_PRED = [](Node<V, F, A>* t, int& key) {
    int sl = t->L ? t->L->size : 0;
    bool ret = sl >= key;
    if (!ret)
        key -= sl + 1;
    return ret;
};

template<typename V, typename F, typename A, typename K>
const auto KEY_PRED = [](Node<V, F, A>* t, const K& key) { return t->val >= key; };

struct Plus {
    int operator()(int a, int b) const {
        return a + b;
    }
};

struct Max {
    int operator()(int a, int b) const {
        return max(a, b);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    TreapUtils<int, int, int, Plus, Plus, Plus, Max> utils{Plus(), Plus(), Plus(), Max()};
    Node<int, int, int>* root{nullptr};
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        auto lh = utils.split(root, r + 1, KEY_PRED<int, int, int, int>);
        auto lm = utils.split(lh.first, l, KEY_PRED<int, int, int, int>);
        if (lm.second)
            lm.second->add += 1;
        root = utils.merge(utils.merge(utils.merge(
                        lm.first, new Node<int, int, int>(l + 1)), lm.second),
                utils.split(lh.second, 1, SIZE_PRED<int, int, int>).second);
    }
    cout << root->size << endl;
}