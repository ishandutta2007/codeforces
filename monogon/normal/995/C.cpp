#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pt complex<ll>
#define x real()
#define y imag()
 
istream &operator>>(istream &is, pt &p) {
    int X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

const int N = 1e5 + 5;
const ll R = 1e6;
int n;
pt p[2 * N];
bool flip[2 * N];
vector<int> adj[2 * N];
vector<int> v;

void dfs(int u) {
    for(int v : adj[u]) {
        flip[v] ^= flip[u];
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        v.push_back(i);
    }
    int c = n;
    while(v.size() >= 3) {
        int sz = v.size();
        int i = v[sz - 1], j = v[sz - 2], k = v[sz - 3];
        v.pop_back(); v.pop_back(); v.pop_back();
        if(norm(p[i] + p[j]) <= R * R) {
            p[c] = p[i] + p[j];
            adj[c] = {i, j};
            v.push_back(k);
        }else if(norm(p[i] - p[j]) <= R * R) {
            p[c] = p[i] - p[j];
            adj[c] = {i, j};
            v.push_back(k);
            flip[j] = true;
        }else if(norm(p[i] + p[k]) <= R * R) {
            p[c] = p[i] + p[k];
            adj[c] = {i, k};
            v.push_back(j);
        }else if(norm(p[i] - p[k]) <= R * R) {
            p[c] = p[i] - p[k];
            adj[c] = {i, k};
            v.push_back(j);
            flip[k] = true;
        }else if(norm(p[j] + p[k]) <= R * R) {
            p[c] = p[j] + p[k];
            adj[c] = {j, k};
            v.push_back(i);
        }else {
            assert(norm(p[j] - p[k]) <= R * R);
            p[c] = p[j] - p[k];
            adj[c] = {j, k};
            v.push_back(i);
            flip[k] = true;
        }
        v.push_back(c++);
    }
    if(v.size() == 2) {
        int i = v[0], j = v[1];
        v.pop_back(); v.pop_back();
        if(norm(p[i] + p[j]) <= R * R * 1.5 * 1.5) {
            p[c] = p[i] + p[j];
            adj[c] = {i, j};
        }else {
            assert(norm(p[i] - p[j]) <= R * R * 1.5 * 1.5);
            p[c] = p[i] - p[j];
            adj[c] = {i, j};
            flip[j] = true;
        }
        v.push_back(c++);
    }
    assert(norm(p[v[0]]) <= R * R * 1.5 * 1.5);
    dfs(v[0]);
    for(int i = 0; i < n; i++) {
        cout << (flip[i] ? -1 : 1) << " ";
    }
    cout << endl;
}