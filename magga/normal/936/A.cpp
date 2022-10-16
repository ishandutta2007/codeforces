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
typedef unsigned long long ll;
using namespace std;
void pre(){}
void solve(){
    ll k,d,t;cin>>k>>d>>t;
    ll i = 1;
    ll c = d;
    t*=2;
    if(d<k){
        if(k%d==0){
            c = k;
        }else{
            c = d*(k/d + 1);
        }
    }else{
        c = d;
    }
    long long int ans = 0;
    long long int process = k*2 + c - k;
    ans = t/process;
    t -= process*ans;
    ans*=c;
    bool flag = 0;
    if(t<=2*k){
        if(t%2==1){
            flag = 1;
        }
        ans += t/2;
    }else{
        ans += k;
        t -= 2*k;
        ans += t;
    }
    if(!flag)
        cout<<ans<<"\n";
    else{
        cout<<ans<<".5"<<"\n";
    }
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