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
#define MAXN   10000001 
int spf[MAXN];  
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
int get(int x){ 
    int ret = 0;
    int val = spf[x]; 
    while (spf[x] == val){ 
        x = x / spf[x]; 
        ret++;
    } 
    return ret; 
}
void pre(){}
void solve(){
    ll n,d,a,b;cin>>n;
    pii ans[n];
    for(int i=0;i<n;i++){
        cin>>d; 
        a = pow(spf[d],get(d));
        b = d/a;
        if(b!=1){
            ans[i].F=a;
            ans[i].S=b;
        }else{
            ans[i].F=-1;
            ans[i].S=-1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i].F<<" ";
    for(int i=0;i<n;i++)
        cout<<ans[i].S<<" ";
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