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
#define MAXN   15000001 
int spf[MAXN];
int ans[MAXN]{0};  
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
void get(int x){  
    while (x != 1){
        int a = spf[x];
        int i = 1;
        while(spf[x]==a){
            i*=a;
            ans[i]++;
            x = x / spf[x]; 
        } 
    }
}
void pre(){}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];get(arr[i]);}
    ll ans1 = 1e10;
    for(int i=2;i<MAXN;i++){
        if(ans[i]>0 && ans[i]!=n){
            ans1= min(ans1,n-ans[i]);
        }
    }
    if(ans1==1e10){
        ans1=-1;
    }
    cout<<ans1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    sieve();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}