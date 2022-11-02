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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 1000006
#define TS 2097152

int Q,N,M,A[MAXN],B[MAXN],V[MAXN],S;
int tree[TS],ST=TS/2-1;

void _add(int n,int v)
{ for (n+=ST;n;n>>=1) tree[n] += v; }

int _find(int idx)
{
    int leafs=TS/4,n=1,ret=0;
    for (;leafs;leafs>>=1){
        if (tree[n+n] < idx){
            idx -= tree[n+n];
            ret += leafs;
            n = n+n+1;
        }
        else n = n+n;
    }
    return ++ret;
}

int main()
{
    int i,v;
    scanf("%d%d",&Q,&M);
    for (i=1;i<=M;i++) scanf("%d",B+i);
    while (Q--){
        scanf("%d",&v);
        if (v < 0){
            for (i=1;i<=M&&B[i]<=S;i++);
            for (;--i;){
                int x = _find(B[i]);
                _add(x,-1); V[x] = 0;
                S--;
            }
        }else{
            A[++N] = v;
            V[N] = 1;
            _add(N,1);
            S++;
        }
    }
    if (!S){ puts("Poor stack!"); return 0; }
    for (i=1;i<=N;i++) if (V[i]) printf("%d",A[i]); puts("");
}