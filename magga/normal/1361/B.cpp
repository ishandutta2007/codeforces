#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
    ll n,p,d;cin>>n>>p;
    map<ll,ll>m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d]++;
    }
    if(p==1){
        if(n%2==0){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
        }
        return;
    }
    ll mo = n,val=0;
    while(mo>0){
        mo/=p;
        val++;
    }
    val++;
    ll req = 0;
    ll ref = -1;
    ll lst;
    bool flag = 0;
    for(auto i = m.rbegin();i!=m.rend();i++){
        auto o = *i;
        if(!flag && o.second%2==0){
            continue;
        }
        if(!flag && o.second%2==1){
            ref = o.first;
            req = 1;
            flag=1;
            lst = o.first;
            continue;
        }
        bool oo = false;
        while(lst>o.first){
            lst--;
            req*=p;
            if(req>n){
                oo =true;
                break;
            }
        }
        if(oo){
            break;
        }
        if(o.second==req){
            flag = false;
            continue;
        }
        if(o.second<req){
            req-=o.second;
            continue;
        }
        if((o.second-req)%2==0){
            flag= false;
        }else{
            flag=true;
            req=1; 
            ref= o.first;
            lst = o.first;
        }
    }
    if(!flag){
        cout<<0<<"\n";
        return;
    }
    ll ans = power(p,ref);
    for(auto i:m){
        if(i.first>=ref){
            break;
        }
        ans=sub(ans,mul(i.second,power(p,i.first)));
    }
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