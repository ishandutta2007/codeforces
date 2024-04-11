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

#define bit(n) (1<<(n))

const int MOD = 1e9 + 7;
int N; lld S,A[20];
int inv[20];
int ans;

int inv_(int n)
{
    int ret = 1, m = MOD-2, v = n;
    for (;m;m>>=1,v=(lld)v*v%MOD) if (m&1){
        ret = (lld)ret*v%MOD;
    }
    return ret;
}

int calc(lld s)
{
    if (s < 0) return 0;
    lld n = s+N-1, r = N-1; int ret = 1;
    for (lld i=n;i>n-r;i--) ret = (lld)ret*(i%MOD)%MOD;
    for (int i=2;i<=r;i++) ret = (lld)ret*inv[i]%MOD;
    return ret;
}

int main()
{
    int i,j;
    scanf("%d%lld",&N,&S);
    for (i=2;i<N;i++) inv[i] = inv_(i);
    for (i=0;i<N;i++) scanf("%lld",A+i);
    for (i=0;i<bit(N);i++){
        int cnt = 0; lld s = S;
        for (j=0;j<N;j++) if (i&bit(j)){
            cnt++;
            s -= A[j]+1;
        }
        int v = calc(s);
        if (cnt&1) ans -= v;
        else ans += v;
        if (ans >= MOD) ans -= MOD;
        if (ans < 0) ans += MOD;
    }
    printf("%d\n",ans);
}