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

int X,N,S[4002],cnt[36001];
lld ans;
char A[4002];

void proc(int side)
{
    int other=X/side;
    if (side > 36000 || other > 36000) return;
    ans += (lld)cnt[side]*cnt[other];
}

int main()
{
    int i,j,k,l;
    scanf("%d%s",&X,A+1); N = strlen(A+1);
    for (i=1;i<=N;i++) S[i] = S[i-1]+A[i]-'0';
    for (i=1;i<=N;i++) for (j=i;j<=N;j++){
        cnt[S[j]-S[i-1]]++;
    }
    if (!X) ans = (lld)cnt[0]*N*(N+1)-(lld)cnt[0]*cnt[0];
    for (i=1;i*i<=X;i++) if (X%i == 0){
        proc(i);
        if (i*i != X) proc(X/i);
    }
    printf("%lld\n",ans);
}