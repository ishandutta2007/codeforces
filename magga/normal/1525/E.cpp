#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

const long long int mod = 998244353;
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
ll fact[1001];
// Please write the recurances once :(
void pre(){
    fact[0]=1;
    for(int i=1;i<100;i++) fact[i] = mul(fact[i-1],i);
}
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>f(m,vector<int>(n+2));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>f[j][0];
            f[j][f[j][0]]++;
            f[j][0]=0;
        }
    }   
    ll ans = 0;
    for(int i=0;i<m;i++){
        ll curr_nums = f[i][n+1];
        ll answer = 1;
        for(int j=n;j>=1;j--){
            answer = mul(answer,curr_nums);
            curr_nums+=f[i][j];
            curr_nums--;
        }
        answer = sub(1,divi(answer,fact[n]));
        ans = add(ans,answer);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}