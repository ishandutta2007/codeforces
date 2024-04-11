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

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;

int T;
lld N,TP[19]={1},TS[19]={1},ans[6];

bool dfs(lld n,int x,int t)
{
    if (!n) return 1;
    if (t < 18 && n > TS[t]*7*6) return 0;
    if (!x) return dfs(n,6,t-1);
    ans[x-1] += TP[t]*7;
    if (n >= 7*TP[t] && dfs(n-7*TP[t],x-1,t)) return 1;
    ans[x-1] -= TP[t]*7;
    ans[x-1] += TP[t]*4;
    if (n >= 4*TP[t] && dfs(n-4*TP[t],x-1,t)) return 1;
    ans[x-1] -= TP[t]*4;
    if (t > 0 && dfs(n,6,t-1)) return 1;
    return 0;
}

int main()
{
    int i;
    for (i=1;i<19;i++) TP[i] = TP[i-1]*10, TS[i] = TS[i-1]+TP[i];
    for (scanf("%d",&T);T--;){
        scanf("%lld",&N);
        set(ans,0);
        if (dfs(N,6,18)){
            for (i=0;i<6;i++) printf("%lld ",ans[i]); puts("");
        }else puts("-1");
    }
}