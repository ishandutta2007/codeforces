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
void pre(){}
set<ll>a,b,c;
void solve(){
    string s;cin>>s;
    a.clear();
    b.clear();
    c.clear();
    ll n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            a.insert(i);
        }else if(s[i]=='2'){
            b.insert(i);
        }else{
            c.insert(i);
        }
    }
    a.insert(1e9);b.insert(1e9);c.insert(1e9);
    ll ans = n+1;
    for(int i=0;i<n;i++){
        ll curr = 0;
        curr=max(max(*a.lower_bound(i),*b.lower_bound(i)),*c.lower_bound(i))-i+1;
        ans=min(ans,curr);
    }
    if(ans>n){
        cout<<0<<"\n";
    }else{
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
//	cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}