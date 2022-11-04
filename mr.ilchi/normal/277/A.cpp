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

const int MAXN = 100+10;

bool mark[2*MAXN];
int n,m;;
vector <int> adj[2*MAXN];

void dfs (int v){
    mark[v] = true;
    for (int i=0; i<(int)adj[v].size(); i++) if (!mark[adj[v][i]])
        dfs(adj[v][i]);
}
int main(){
    cin >> n >> m;
    bool all0 = true;
    for (int i=1; i<=n; i++){
        int len; cin >> len;
        for (int j=0; j<len; j++){
            int temp; cin >> temp; temp+=n;
            adj[temp].push_back(i);
            adj[i].push_back(temp);
        }
        all0 = all0 & (len==0);
    }
    int comp = 0;
    for (int i=1; i<=n; i++) if (!mark[i]){
        dfs(i);
        comp++;
    }
    cout << comp-1 + all0 << endl;
    return 0;
}