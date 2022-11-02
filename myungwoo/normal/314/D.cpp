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
typedef pair<lld,int> pli;

#define MAXN 100005

int N,X[MAXN],Y[MAXN]; lld ans;
bool vis[MAXN];
vector <pii> P,Q;
priority_queue <pii> mx,mn;

bool proc(lld m)
{
    int i,prev,idx;
    while (!mx.empty()) mx.pop();
    while (!mn.empty()) mn.pop();
    for (i=1;i<=N;i++) vis[i] = 0;
    for (i=0;i<N;i++){
        mx.push(mp(Q[i].fr,Q[i].sc));
        mn.push(mp(-Q[i].fr,Q[i].sc));
    }
    for (i=prev=0;i<N;i++){
        while (prev < i && P[prev].fr < P[i].fr-m){
            idx = P[prev].sc;
            vis[idx] = 0;
            mx.push(mp(X[idx]+Y[idx],idx));
            mn.push(mp(-(X[idx]+Y[idx]),idx));
            prev++;
        }
        vis[P[i].sc] = 1;
        while (!mx.empty() && vis[mx.top().sc]) mx.pop();
        while (!mn.empty() && vis[mn.top().sc]) mn.pop();
        if (mx.empty() || (lld)mx.top().fr+mn.top().fr <= m) return 1;
    }
    return 0;
}

int main()
{
    int i,j;
    lld s,e,m;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d%d",X+i,Y+i);
        P.pb(mp(X[i]-Y[i],i));
        Q.pb(mp(X[i]+Y[i],i));
    }
    sort(all(P)), sort(all(Q));
    s = 0, e = 4e9;
    while (s <= e){
        m = (s+e)>>1;
        if (proc(m)) e = m-1, ans = m;
        else s = m+1;
    }
    printf("%lld.%d\n",ans>>1,ans&1?5:0);
}