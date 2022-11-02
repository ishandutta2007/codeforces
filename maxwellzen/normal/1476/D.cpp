#include <bits/stdc++.h>

using namespace std;
#define pb push_back
const int MxN = 3e5+1;
int t, n;
string s;

void solve() {
    cin >> n >> s;
    set<int> adj[2][n+1];
    int ans[2][n+1];
    bool checked[2][n+1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            checked[i][j]=false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i]=='L') {
            adj[0][i+1].insert(i);
            adj[1][i].insert(i+1);
        } else {
            adj[0][i].insert(i+1);
            adj[1][i+1].insert(i);
        }
    }
    for (int i = 0; i <= n; i++) {
        if (checked[0][i]) {cout << ans[0][i] << " "; continue;}
        int c = i, tt = 0, mini=i, maxi=i;
        while (adj[tt][c].find(c-1)!=adj[tt][c].end()) {
            mini--;
            c--;
            tt = 1-tt;
        }
        c=i; tt=0;
        while (adj[tt][c].find(c+1)!=adj[tt][c].end()) {
            maxi++;
            c++;
            tt = 1-tt;
        }
        ans[0][i]=maxi-mini+1;
        c=i, tt=0;
        while (adj[tt][c].find(c-1)!=adj[tt][c].end()) {
            c--;
            tt = 1-tt;
            ans[tt][c] = ans[0][i];
            checked[tt][c]=true;
        }
        c=i; tt=0;
        while (adj[tt][c].find(c+1)!=adj[tt][c].end()) {
            c++;
            tt = 1-tt;
            ans[tt][c] = ans[0][i];
            checked[tt][c]=true;
        }
        cout << ans[0][i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}