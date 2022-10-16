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
    ll n,m,u,v,d;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    ll val[n+1]; 
    pii ar[n];
    for(int i=0;i<n;i++){
        cin>>d;
        val[i+1]=d;
        ar[i]= {d,i+1};
    }
    sort(ar,ar+n);
    set<int>s;
    for(int i=0;i<n;i++){
        s.clear();
        for(auto j:arr[ar[i].second]){
            s.insert(val[j]);
            //cout<<val[j]<<" ";
        }
        //cout<<"\n";
        int ans = 1;
        while(s.find(ans)!=s.end()){
            ans++;
        }
        //cout<<ans<<" "<<ar[i].s<<"\n";
        if(ans!=ar[i].first){
            cout<<-1<<"\n";
            return;
        }
    }
    for(auto i:ar){
        cout<<i.second<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}