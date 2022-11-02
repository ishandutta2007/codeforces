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

#define MAXN 100005

int N,M,S,A[MAXN],D[1<<20],cnt[20],ans=2e9;

int main()
{
    int i,j,k,msk;
    scanf("%d%d%d",&N,&M,&S);
    for (i=0;i<M;i++){
        for (scanf("%d",&j);j--;) scanf("%d",&k), A[k] = i;
    }
    for (i=1;i<=N;i++){
        cnt[A[i]]++;
        if (i > S) cnt[A[i-S]]--;
        if (i < S) continue;
        msk = 0;
        for (j=0;j<M;j++) if (cnt[j]) msk |= (1<<j);
        D[(1<<M)-1-msk] = 1;
    }
    for (msk=(1<<M);msk--;) if (D[msk]){
        for (i=0;i<M;i++) if (msk&(1<<i)) D[msk^(1<<i)] = 1;
    }
    for (msk=0;msk<(1<<M);msk++) if (!D[msk]){
        int c=0;
        for (i=0;i<M;i++) if (msk&(1<<i)) c++;
        if (ans > c) ans = c;
    }
    printf("%d\n",ans);
}