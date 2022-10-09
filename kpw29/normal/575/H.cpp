#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define FORD(i,s,e) for(int i=s;i>=e;i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define MP make_pair
#define EB emplace_back
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MAXN=5000111;
const LL MOD=(int)1e9+7;
LL silnia[MAXN];
LL pot(LL a,LL wykl){
    LL wyn=1;
    while(wykl>0){
        if(wykl%2) wyn*=a,wyn%=MOD;
        a*=a;a%=MOD;
        wykl/=2;
    }
    return wyn;
}
LL odwr(LL a){return pot(a,MOD-2);}
main(){
    int n;scanf("%d",&n);n++;
    silnia[0]=1;
    FOR(i,1,3*n) silnia[i]=(silnia[i-1]*i)%MOD;
    LL gora=(2*silnia[2*n-1])%MOD;
    LL dol=(silnia[n]*silnia[n-1])%MOD;
    dol=odwr(dol);
    gora=(gora*dol-1)%MOD;
    if(gora<0) gora+=MOD;
    printf("%I64d\n",gora % MOD);
    
}