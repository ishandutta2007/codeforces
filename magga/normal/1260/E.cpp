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
void solve(){
    ll n;cin>>n;
    vector<long long int>v;
    ll d;
    ll k = __builtin_ctz(n);
    int a = 0;
    for(int i=0;i<n;i++){
        cin>>d;
        if(!a && d!=-1)
            v.push_back(0);
        else if(d==-1)
            a = 1;
        else
            v.push_back(d);
    }
    ll curr = v.size()-1;
    ll ans = 0;
    multiset<long long int>ms;
    ll oo = 2;
    for(int i=0;i<k;i++){
        ms.insert(v[curr]);
        curr--;
        ans+=*ms.begin();
        ms.erase(ms.begin());
        for(int j=0;j<n/oo-1;j++){
            ms.insert(v[curr]);
            curr--;
        }
        oo*=2;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}