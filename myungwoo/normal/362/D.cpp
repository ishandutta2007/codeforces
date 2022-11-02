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
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;
typedef pair<lld,int> pli;

#define MAXN 100005

int N,M,P,Q,R;
int mom[MAXN];
lld S[MAXN];
priority_queue <pli> que;
vector <pii> list;

int _find(int n){ return mom[n]==n?n:(mom[n]=_find(mom[n])); }

int main()
{
    int i,j,k,v;
    scanf("%d%d%d%d",&N,&M,&P,&Q);
    if (M+P > 0 && Q == N){ puts("NO"); return 0; }
    for (i=1;i<=N;i++) mom[i] = i;
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&v);
        j = _find(j), k = _find(k);
        if (j == k) S[j] += v;
        else{
            mom[k] = j;
            S[j] += S[k], S[j] += v;
        }
    }
    for (i=1;i<=N;i++) if (_find(i) == i) que.push(mp(-S[i],i)), R++;
    if (R < Q){ puts("NO"); return 0; }
    while (R > Q && P){
        R--; P--;
        int a = que.top().sc; que.pop();
        int b = que.top().sc; que.pop();
        mom[b] = a;
        S[a] += S[b];
        S[a] += min((lld)1e9,S[a]+1);
        list.pb(mp(a,b));
        que.push(mp(-S[a],a));
    }
    if (R > Q){ puts("NO"); return 0; }
    if (Q < N){
        for (i=1;i<=N;i++) if (_find(i) == i && S[i]) break;
        for (j=1;j<=N;j++) if (i == _find(j) && i != j) break;
        while (P--) list.pb(mp(i,j));
    }
    puts("YES");
    for (i=0;i<sz(list);i++) printf("%d %d\n",list[i].fr,list[i].sc);
}