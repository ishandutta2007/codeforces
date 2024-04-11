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
#define MAXN   100001 
ll m;
int spf[MAXN];
int val[MAXN];  
void sieve(){ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}  
vector<int> getFactorization(int x){ 
    set<int> ret;
    vector<int>re;
    while (x != 1){ 
        ret.insert(spf[x]); 
        x = x / spf[x]; 
    } 
    for(auto i :ret){
        re.push_back(i);
    }
    return re; 
}
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
void pre(){
    sieve();
    for(int i=2;i<=m;i++){
        val[i]=0;
        auto j = getFactorization(i);
        for(int k=0;k<j.size();k++)
            val[i]+=m/j[k];
        if(j.size()==1) continue;
        for(int k=0;k<j.size();k++)
            for(int l = k+1;l<j.size();l++)
                val[i]-=m/(j[k]*j[l]);
        if(j.size()==2) continue;
        for(int k=0;k<j.size();k++)
            for(int l = k+1;l<j.size();l++)
                for(int n = l+1;n<j.size();n++)
                    val[i]+=m/(j[k]*j[l]*j[n]);
        if(j.size()==3) continue;
        for(int k=0;k<j.size();k++)
            for(int l = k+1;l<j.size();l++)
                for(int n = l+1;n<j.size();n++)
                    for(int o = n+1;o<j.size();o++)
                        val[i]-=m/(j[k]*j[l]*j[n]*j[o]);
        if(j.size()==4) continue;
        for(int k=0;k<j.size();k++)
            for(int l = k+1;l<j.size();l++)
                for(int n = l+1;n<j.size();n++)
                    for(int o = n+1;o<j.size();o++)
                        for(int p = o+1;p<j.size();p++)
                            val[i]+=m/(j[k]*j[l]*j[n]*j[o]*j[p]);
        if(j.size()==5) continue;
        for(int k=0;k<j.size();k++)
            for(int l = k+1;l<j.size();l++)
                for(int n = l+1;n<j.size();n++)
                    for(int o = n+1;o<j.size();o++)
                        for(int p = o+1;p<j.size();p++)
                            for(int q = p+1;q<j.size();q++)
                                val[i]-=m/(j[k]*j[l]*j[n]*j[o]*j[p]*j[q]);
    }
}
void solve(){
    ll n;cin>>m;
    n = m;
    pre();
    ll ans[100001]{0};
    for(ll i=2;i<=n;i++){
        ll p = divi(n/i,n);
        ans[i]=divi(sub(mul(2,p),mul(p,p)),power(sub(1,p),2));
    }
    for(ll i = n;i>=2;i--){
        for(ll j = 2;i*j<=n;j++){
            ans[i]=sub(ans[i],ans[i*j]);
        }
    }
    ll an = divi(1,n);
    for(ll i=2;i<=n;i++){
        ll p = divi(val[i],n);
        an+=mul(ans[i],sub(1,p));
        an%=mod;
    }
    cout<<an<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();   
}