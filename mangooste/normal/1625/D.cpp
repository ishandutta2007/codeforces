#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, mn_xor;
    cin >> n >> mn_xor;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    if (mn_xor == 0) {
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << i + 1 << " \n"[i ==  n - 1];

        cout << '\n';
        return 0;
    }

    int bit = __lg(mn_xor);
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) {
        return a[i] < a[j];
    });
    sort(all(a));

    auto get = [](int x, int b) {
        return x >> b << b;
    };

    vector<int> answer;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && get(a[i], bit) == get(a[j], bit))
            j++;

        if (j == n || get(a[i], bit + 1) != get(a[j], bit + 1)) {
            answer.push_back(order[i]);
            i = j;
            continue;
        }

        int j2 = j + 1;
        while (j2 < n && get(a[j], bit) == get(a[j2], bit))
            j2++;

        struct node {
            int id = -1;
            array<node*, 2> childs = {nullptr, nullptr};

            ~node() {
                delete childs[0];
                delete childs[1];
            }
        };

        node* root = new node();
        for (int k = i; k < j; k++) {
            auto v = root;
            for (int level = bit - 1; level >= 0; level--) {
                int cur = a[k] >> level & 1;
                if (!v->childs[cur])
                    v->childs[cur] = new node();

                v = v->childs[cur];
            }
            v->id = k;
        }

        bool found = false;
        for (int k = j; k < j2; k++) {
            auto v = root;
            for (int level = bit - 1; level >= 0; level--) {
                int cur = a[k] >> level & 1;
                if (v->childs[cur ^ 1])
                    v = v->childs[cur ^ 1];
                else
                    v = v->childs[cur];
            }

            if ((a[k] ^ a[v->id]) >= mn_xor) {
                found = true;
                answer.push_back(order[v->id]);
                answer.push_back(order[k]);
                break;
            }
        }
        delete root;

        if (!found)
            answer.push_back(order[i]);

        i = j2;
    }

    if (len(answer) < 2) {
        cout << "-1\n";
        return 0;
    }

    cout << len(answer) << '\n';
    for (int i = 0; i < len(answer); i++)
        cout << answer[i] + 1 << " \n"[i == len(answer) - 1];
}