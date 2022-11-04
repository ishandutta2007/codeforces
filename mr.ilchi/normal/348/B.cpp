/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

const int MAXN = 100000+10;

bool mark[MAXN];
int n;
int a[MAXN];
LL sum = 0;
vector <int> adj[MAXN];
vector <pli> comb;

inline void dfs(int v, LL h){
    if (h>sum){
        cout << sum << endl;
        exit(0);
    }
    mark[v] = true;
    int child = (int)adj[v].size() - (v!=0);
    for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
        dfs(adj[v][i], h * child);
    if (child == 0)
        comb.push_back(pli(h, a[v])); 
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sum = 0;
    for (int i=0; i<n; i++)
        sum+= a[i];
    for (int i=0; i<n-1; i++){
        int e1,e2; cin >> e1 >> e2;
        e1--; e2--;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }
    dfs(0,1LL); 
    LL lcm = 1;
    for (int i=0; i<(int)comb.size(); i++){
        LL d = __gcd(comb[i].first, lcm);
        lcm = lcm/d * comb[i].first;
        if (lcm > sum){
            cout << sum << endl;
            return 0;
        }
    }
    LL ans = (1LL<<60);
    for (int i=0; i<(int)comb.size(); i++)
        ans = min(ans, (comb[i].second * comb[i].first) / lcm * lcm);
    cout << sum - ans << endl;
    return 0;
}