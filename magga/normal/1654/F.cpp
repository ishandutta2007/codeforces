#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define INF 1000000000
#define pii pair<long long int,long long int>
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
ll p1 = 29,p2 = 31;
struct Hasher{
    int n;
    vector<ll>val;
    vector<pii>hash;
    Hasher *left,*right;
    Hasher(){};
    void build(string _s,int _n){
        n = _n;
        val.resize(_s.size());
        hash.resize(_s.size());
        for(int i=0;i<_s.size();i++) val[i] = _s[i] - 'a';
        if(_s.size()==1){
            hash[0] = {val[0],val[0]};
        }else{
            left = new Hasher(_s.substr(0,_s.size()/2),n-1);
            right = new Hasher(_s.substr(_s.size()/2),n-1);
            ll mul1 = power(p1,_s.size()/2);
            ll mul2 = power(p2,_s.size()/2);
            for(int i=0;i<_s.size()/2;i++){
                hash[i].F = add((*left).hash[i].F,mul((*right).hash[i].F,mul1));
                hash[i].S = add((*left).hash[i].S,mul((*right).hash[i].S,mul2));
                hash[i+_s.size()/2].F = add((*right).hash[i].F,mul((*left).hash[i].F,mul1));
                hash[i+_s.size()/2].S = add((*right).hash[i].S,mul((*left).hash[i].S,mul2));
            }
        }
    } 
    Hasher(string _s,int _n){
        build(_s,_n);
    } 
     
};
Hasher abstractor;
bool compare(const int lhs,const int rhs){
    ll l = lhs;
    ll r = rhs;
    Hasher *currlhs = &abstractor ;
    Hasher *currrhs = &abstractor ; 
    if(((*currlhs).hash[l])==((*currrhs).hash[r])) return false;
    for(int i=abstractor.n-1;i>=0;i--){
        Hasher *llhs = currlhs->left;
        Hasher *lrhs = currrhs->left;
        Hasher *rlhs = currlhs->right;
        Hasher *rrhs = currrhs->right;
        if(l&(1<<i)) swap(llhs,rlhs);
        if(r&(1<<i)) swap(lrhs,rrhs);
        r = ( r | (1ll<<i) ) ^ (1ll<<i);
        l = ( l | (1ll<<i) ) ^ (1ll<<i);
        if(((*llhs).hash[l])==((*lrhs).hash[r])){
            currlhs = rlhs;
            currrhs = rrhs;
        }else{
            currlhs = llhs;
            currrhs = lrhs;
        }
    }
    return (*currlhs).val[0] < (*currrhs).val[0];  
} 
void pre(){}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    abstractor.build(s,n);
    int mask = 0;
    for(int i=1;i<s.size();i++){
        if(compare(i,mask)){
            mask = i;
        }
    }
    string ans = s;
    for(int i=0;i<s.size();i++){
        ans[i] = s[i^mask];
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}