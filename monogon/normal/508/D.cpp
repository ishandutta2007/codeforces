
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;
const int N = 62;
vector<int> adj[N * N], adjr[N * N];

int val(char a) {
    if(a >= '0' && a <= '9') return a - '0';
    else if(a >= 'a' && a <= 'z') return (a - 'a') + 10;
    return (a - 'A') + 36;
}
int val(char a, char b) {
    return N * val(a) + val(b);
}
char invval(int x) {
    if(x >= 0 && x <= 9) return x + '0';
    else if(x >= 10 && x < 36) return (x - 10) + 'a';
    else return (x - 36) + 'A';
}
char invval1(int x) {
    return invval(x / N);
}
char invval2(int x) {
    return invval(x % N);
}

stack<int> st;
void dfs(int x) {
    while(adj[x].size()) {
        int y = adj[x].back();
        adj[x].pop_back();
        dfs(y);
    }
    st.push(x);
}
void solve() {
    if((int) st.size() < n + 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    s = "";
    s += invval1(st.top());
    s += invval2(st.top());
    st.pop();
    while(st.size()) {
        s += invval2(st.top());
        st.pop();
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        int u = val(s[0], s[1]);
        int v = val(s[1], s[2]);
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    int in1 = 0, out1 = 0;
    for(int i = 0; i < N * N; i++) {
        int val = (int) adj[i].size() - (int) adjr[i].size();
        if(val == 1) in1++;
        else if(val == -1) out1++;
        else if(val != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(in1 > 1 || out1 > 1) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < N * N; i++) {
        if(adj[i].size() == adjr[i].size() + 1) {
            dfs(i);
            solve();
            return 0;
        }
    }
    for(int i = 0; i < N * N; i++) {
        if(adj[i].size()) {
            dfs(i);
            solve();
            return 0;
        }
    }
    cout << "NO" << endl;
}