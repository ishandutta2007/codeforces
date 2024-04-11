
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n, p[N], c[N], a[N], sz[N];
bool b[N], flag;
vector<int> adj[N];

struct node {
    int val;
    node *next;
};

node* dfs(int x) {
    if(flag) return nullptr;
    int cnt = 0;
    node *head = new node;
    head->next = nullptr;
    node *tail = head;
    for(int y : adj[x]) {
        node *p = dfs(y);
        if(p == nullptr) {
            flag = true;
            return nullptr;
        }
        tail->next = p->next;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        cnt += sz[y];
    }
    sz[x] = cnt + 1;
    if(c[x] > cnt) {
        flag = true;
        return nullptr;
    }
    tail = head;
    for(int i = 0; i < c[x]; i++) {
        tail = tail->next;
    }
    node *p = new node;
    p->val = x;
    p->next = tail->next;
    tail->next = p;
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        adj[p[i]].push_back(i);
    }
    node *p = dfs(adj[0][0]);
    if(flag) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        p = p->next;
        a[p->val] = i;
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}