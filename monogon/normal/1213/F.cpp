
#include <iostream>
#include <stack>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, k;
int p[N], q[N];
int adj[N][2], adjout[N][2];
int sz[N], szout[N];
bool visited[N];
stack<int> st;
char ch[N];

int parent[N];

int find(int x) {
    return parent[x] == -1 ? x : parent[x] = find(parent[x]);
}

void dfs1(int i) {
    if(visited[i]) {
        return;
    }
    visited[i] = true;
    for(int j = 0; j < sz[i]; j++) {
        dfs1(adj[i][j]);
    }
    st.push(i);
}
void dfs2(int i, int p) {
    if(visited[i]) {
        return;
    }
    visited[i] = true;
    if(i != p)
        parent[i] = p;
    for(int j = 0; j < szout[i]; j++) {
        dfs2(adjout[i][j], p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    fill(parent, parent + n, -1);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    for(int i = 1; i < n; i++) {
        adj[p[i - 1]][sz[p[i - 1]]++] = p[i];
        adjout[p[i]][szout[p[i]]++] = p[i - 1];
        adj[q[i - 1]][sz[q[i - 1]]++] = q[i];
        adjout[q[i]][szout[q[i]]++] = q[i - 1];
    }
    for(int i = 0; i < n; i++) {
        dfs1(i);
    }
    fill(visited, visited + n, false);

    int pars = 0;
    while(st.size()) {
        int x = st.top();
        if(!visited[x]) {
            ch[x] = min(pars, k - 1) + 'a';
            pars++;
        }
        dfs2(x, x);
        st.pop();
    }

    if(pars < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << ch[find(i)];
    }
    cout << endl;
}