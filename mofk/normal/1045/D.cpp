#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
#define X first
#define Y second
 
 
const int N = 1e5 + 10;
const int THRESH = 400;
 
double a[N];
double sumA[N];
vector<int> adj[N], hV;
vector<ii> hE;
int n;
 
bool isHeavy(int u) {
    return adj[u].size() > THRESH;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = 1 - a[i];
    }
 
 
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double ansV = 0, ansELL = 0;
    for(int u = 0; u < n; u++) {
        ansV += a[u];
        for(auto v : adj[u]) if (u < v) {
            if (!isHeavy(u) && !isHeavy(v)) ansELL += a[u] * a[v]; 
        }
    
        if (isHeavy(u)) {
            hV.push_back(u);
            for(auto v : adj[u]) {
                if (isHeavy(v)) {
                    hE.push_back(ii(u, v));
                } else sumA[u] += a[v];
            }
        }
    }
 
    int test;
    cin >> test;
    while (test--) {
        int u; 
        double newA;
        cin >> u >> newA; newA = 1 - newA;
        if (!isHeavy(u)) {
            for(auto v : adj[u]) {
                if (!isHeavy(v)) {
                    ansELL += (newA - a[u]) * a[v];
                } else {
                    sumA[v] += newA - a[u];
                }
            }
        }
        ansV += newA - a[u];
        a[u] = newA;
 
        double ansE = ansELL;
        for(auto u : hV) ansE += a[u] * sumA[u];
        for(auto i : hE) ansE += a[i.X] * a[i.Y];
        printf("%.9f\n", ansV - ansE);
    }
}