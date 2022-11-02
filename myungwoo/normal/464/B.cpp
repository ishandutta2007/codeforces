#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

const int N = 8;
vector < vector<int> > A;

bool proc()
{
    int i,j,k;
    vector <lld> dist;
    for (i=0;i<N;i++) for (j=i+1;j<N;j++){
        lld d = 0;
        for (k=0;k<3;k++) d += (lld)(A[i][k]-A[j][k])*(A[i][k]-A[j][k]);
        dist.pb(d);
    }
    sort(all(dist));
    if (dist[0] == 0) return 0;
    for (i=0;i<12;i++) if (dist[i] != dist[0]) return 0;
    if (dist[0] == dist[12]) return 0;
    for (i=12;i<24;i++) if (dist[i] != dist[12]) return 0;
    if (dist[24] == dist[12]) return 0;
    for (i=24;i<28;i++) if (dist[i] != dist[24]) return 0;
    return 1;
}

bool dfs(int n)
{
    if (n == N) return proc();
    do{
        if (dfs(n+1)) return 1;
    } while (next_permutation(all(A[n])));
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    for (i=0;i<N;i++){
        vector <int> a;
        for (j=3;j--;){
            cin >> k;
            a.pb(k);
        }
        sort(all(a));
        A.pb(a);
    }
    if (!dfs(1)){ cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    for (i=0;i<N;i++){
        for (j=0;j<3;j++) cout << A[i][j] << " ";
        cout << endl;
    }
}