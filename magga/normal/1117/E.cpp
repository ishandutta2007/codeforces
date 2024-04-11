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
ll p[3]={23,25,26};
ll phi[3]={22,20,12};
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y, long long int mod){  
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
long long int inv(long long int a,long long int mod){return power(a,mod-2,mod);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
string query(string s){
    cout<<"? "<<s<<"\n";
    cout.flush();
    string pp;cin>>pp;
    return pp;
}
void pre(){}
void solve(){
    string t;cin>>t;
    ll n = t.size();
    string arr[3];
    for(int j=0;j<3;j++)
    for(int i=0;i<n;i++){
        arr[j] += char('a'+ i%p[j]);
    }
    for(int i=0;i<3;i++){
       arr[i] = query(arr[i]);
    }
    ll val[n];
    ll opsie = 23*25*26;
    for(int i=0;i<n;i++){
        int a = arr[0][i]-'a';
        int b = arr[1][i]-'a';
        int c = arr[2][i]-'a';
        val[i] = a*(opsie/23)*power(opsie/23,phi[0]-1,p[0]) + b*(opsie/25)*power(opsie/25,phi[1]-1,p[1]) + c*(opsie/26)*power(opsie/26,phi[2]-1,p[2]);
        val[i]%=opsie;
        cout.flush();
    }
    string ans = t;
    for(int i=0;i<n;i++){
        ans[val[i]]=t[i];
    }
    cout<<"! "<<ans<<"\n";
    cout.flush();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}