
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105, MAX_M = 1e6 + 5;
int n, m, vlen;
string s;
int adj[MAX_N][MAX_N];
int v[MAX_M];
int p[MAX_M];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                adj[i][j] = 0;
            }else if(s[j] == '0') {
                adj[i][j] = INT_MAX;
            }else {
                adj[i][j] = 1;
            }
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][k] < INT_MAX && adj[k][j] < INT_MAX && 
                        adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int lasti = 0;
    v[0] = p[0];
    vlen = 1;
    for(int i = 1; i < m; i++) {
        if(adj[v[vlen - 1]][p[i]] < i - lasti) {
            v[vlen++] = p[i - 1];
            lasti = i - 1;
        }
    }
    v[vlen++] = p[m - 1];
    cout << vlen << endl;
    for(int i = 0; i < vlen; i++) {
        cout << (v[i] + 1) << " ";
    }
    cout << endl;
}