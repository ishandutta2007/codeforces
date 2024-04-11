#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
void pre(){}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    ll count[61]{0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<60;j++){
            if(arr[i]&(1ll<<j)){
                count[j]++;
            }
        }
    }
    ll ans = 0;
    ll ref[60];
    ref[0]=1;
    for(int i=1;i<60;i++){
        ref[i] = (ref[i-1]*2)%mod;
    }
    for(int j=0;j<n;j++){
        ll temp = 0;
        ll temp2 = 0;
        for(int k=0;k<60;k++){
            if( arr[j] & (1ll<<k) ){
                temp += mul(n,ref[k]);
                temp2 += mul(count[k],ref[k]);
            }else{
                temp += mul(count[k],ref[k]);
            }
            temp%=mod;
            temp2%=mod;
        }
        ans += mul(temp,temp2);
    }
    ans%=mod;
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}