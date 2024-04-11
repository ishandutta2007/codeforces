#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

const int MAXN = 100000;

int make_rand() {
    return rand();
}

struct node {
    int key;
    int prior;
    int size;
    int cnt;
    node *left, *right;

    node(int key = 0) : key(key), left(nullptr), right(nullptr) {
        prior = make_rand();
        size = 1;
        cnt = 1;
    }
};

vector<int> g[MAXN + 1];
vector<pair<int, int>> queries[MAXN + 1];
int a[MAXN + 1], ans[MAXN + 1], cur_buf = 0, sz[MAXN + 1];
node buf[10 * MAXN + 1];

int get_size(node* root) {
    return root ? root->size : 0;
}

void update(node* root) {
    if (!root) {
        return;
    }
    root->size = get_size(root->left) + get_size(root->right) + root->cnt;
}

pair<node*, node*> split(node* root,  int key) {
    if (!root) {
        return { nullptr, nullptr };
    }
    if (root->key < key) {
        pair<node*, node*> splt = split(root->right, key);
        root->right = splt.first;
        update(root);
        return { root, splt.second };
    } else {
        pair<node*, node*> splt = split(root->left, key);
        root->left = splt.second;
        update(root);
        return { splt.first, root };
    }
}

node* merge(node* left, node* right) {
    if (!left || !right) {
        return left ? left : right;
    }
    if (left->prior > right->prior) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

void erase(node*& root, int key) {
    assert(root);
    if (key < root->key) {
        erase(root->left, key);
    } else if (key > root->key) {
        erase(root->right, key);
    } else {
        --root->cnt;
        if (root->cnt == 0) {
            root = merge(root->left, root->right);
        }
    }
    update(root);
}

void insert(node*& root, node* nw) {
    if (!root) {
        root = nw;
    } else if (root->prior > nw->prior) {
        if (nw->key < root->key) {
            insert(root->left, nw);
        } else {
            insert(root->right, nw);
        }
    } else {
        pair<node*, node*> splt = split(root, nw->key + 1);
        nw->left = splt.first;
        nw->right = splt.second;
        root = nw;
    }
    update(root);
}

void insert_fast(node*& st, node* nw) {
    if (!st) {
        st = nw;
        return;
    }
    auto root = st;
    while (root && root->key != nw->key) {
        if (nw->key < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if (!root) {
        insert(st, nw);
    } else {
        root = st;
        while (root && root->key != nw->key) {
            ++root->size;
            if (nw->key < root->key) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        ++root->size;
        ++root->cnt;
    }
}

int get_cnt(node*& root, int key) {
    pair<node*, node*> temp1 = split(root, key);
    int result = get_size(temp1.second);
    root = merge(temp1.first, temp1.second);
    return result;

}

void print(node* root) {
    if (!root) {
        return;
    }
    print(root->left);
    cout << "(" << root->key << "; " << root->cnt << ")" << " ";
    print(root->right);
}

void debug(node* root) {
    cout << "!!!\n";
    print(root);
    cout << "\n!!!" << endl;
}

node* new_node(int key) {
    buf[cur_buf].key = key;
    return &buf[cur_buf++];
}

pair<map<int, int>, node*> dfs(int v, int p) {
    map<int, int> cur;
    cur[a[v]] = 1;
    node* root = new_node(1);
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        pair<map<int, int>, node*> temp = std::move(dfs(u, v));
        map<int, int>& s = temp.first;
        node* nw = temp.second;

        if (cur.size() < s.size()) {
            cur.swap(s);
            swap(root, nw);
        }

        for (const auto& it : s) {
            auto p = cur.find(it.first);
            if (p != cur.end()) {
                erase(root, p->second);
            }
            cur[it.first] += it.second;
            insert_fast(root, new_node(cur[it.first]));
        }
        s.clear();
    }

    /*cout << v << ":\n";
    debug(root);
    for (const auto& it : cur) {
        cout << it.first << " " << it.second << "\n";
    }*/

    for (const auto& q: queries[v]) {
        ans[q.second] = get_cnt(root, q.first);
    }

    return { std::move(cur), root };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    srand(time(NULL));

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        --v;
        queries[v].push_back({ k, i });
    }

    dfs(0, -1);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}