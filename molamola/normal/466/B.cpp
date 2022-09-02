#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

ll n;

int main()
{
//freopen("input.txt","r",stdin);
    ll a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    ll m = 6*n;
    if((ll)a * b >= m){printf("%lld\n%lld %lld\n",(ll)a*b, a, b);return 0;}
    int swaped = 0;
    if(a > b)swaped = 1, swap(a,b);
    ll now = 2e18;
    ll a0=a, b0=b;
    for(int i=a;i<=sqrt(m);++i){
        ll t = (m % i == 0) ? m/i : m/i+1;
        if(t < b)continue;
        if(now > -m + t * i){
            now = -m + t*i;
            a0 = i, b0 = t;
        }
    }
    if(!swaped)printf("%lld\n%lld %lld",a0*b0,a0,b0);
    else printf("%lld\n%lld %lld",a0*b0,b0,a0);
    return 0;
}