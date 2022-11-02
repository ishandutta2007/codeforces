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

#define MAXN 10004
#define MAXM 100005

int N,M,P,G,ans;
int A[MAXN],B[MAXM],R[MAXN];
vector <int> divs;

lld gcd(lld a,lld b){ return b?gcd(b,a%b):a; }

int _pow(int n,int p,int mod)
{
    if (!p) return 1;
    lld v=_pow(n,p>>1,mod);
    return v*v%mod*((p&1)?n:1)%mod;
}

int get_period(int n)
{
    int i;
    for (i=0;i<sz(divs);i++){
        if (_pow(n,divs[i],P) == 1) return divs[i];
    }
}

int fi(int n)
{
    int ret=n,i;
    for (i=2;i*i<=n;i++) if (n%i == 0){
        ret -= ret/i;
        while (n%i == 0) n /= i;
    }
    if (n > 1) ret -= ret/n;
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&P);
    for (i=1;i*i<P;i++) if ((P-1)%i == 0){
        divs.pb(i); divs.pb((P-1)/i);
    }
    sort(all(divs));
    divs.erase(unique(all(divs)),divs.end());
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=M;i++) scanf("%d",B+i);
    G = P-1;
    for (i=1;i<=M;i++) G = gcd(G,B[i]);
    for (i=1;i<=N;i++){
        k = get_period(A[i]);
        R[i] = k/gcd(k,G);
    }
    for (i=0;i<sz(divs);i++){
        for (j=1;j<=N;j++) if (R[j]%divs[i] == 0){
            ans += fi(divs[i]);
            break;
        }
    }
    printf("%d\n",ans);
}