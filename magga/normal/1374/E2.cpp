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
const long long int N =65536;
long long int n = 65535;
pii t[2*N]{{0,0}};
pii combine(pii &a,pii &b){
    return {a.F+b.F,a.S+b.S};
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void add(long long int p){
    t[p+=n].F++;
    t[p].S+=p-n;
    for(;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
void sub(long long int p){
    t[p+=n].F--;
    t[p].S-=p-n;
    for(;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
pii query(long long int m){
    pii ret = {0,0};
    ll curr = 1;
    while(curr<n){
        curr<<=1;
        if(ret.F+t[curr].F<=m){
            ret.F+=t[curr].F;
            ret.S+=t[curr].S;
            curr|=1;
        }
    }
    if(curr<n+10001 && ret.F + t[curr].F > m ){
        ret.S+=(m-ret.F)*(curr-65535);
        ret.F=m;
    }
    return ret;
}
void pre(){}
vector<pii>arr[4];
vector<long long int>dp[4];
void construct(){
    sort(arr[0].begin(),arr[0].end());
    sort(arr[1].begin(),arr[1].end());
    sort(arr[2].begin(),arr[2].end());
    sort(arr[3].begin(),arr[3].end());
    dp[0].resize(arr[0].size()+1,0);
    dp[1].resize(arr[1].size()+1,0);
    dp[2].resize(arr[2].size()+1,0);
    dp[3].resize(arr[3].size()+1,0);
    for(int i=0;i<4;i++){
        for(int j=1;j<=arr[i].size();j++){
            dp[i][j]=dp[i][j-1]+arr[i][j-1].F;
        }
    }
}
void solve(){
    ll n,k,m;cin>>n>>m>>k;
    ll a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(b & c){
            arr[3].push_back({a,i+1});
            t[65535+a].F++;
            t[65535+a].S+=a;
        }else if(b){
            arr[1].push_back({a,i+1});
        }else if(c){
            arr[2].push_back({a,i+1});
        }else{
            arr[0].push_back({a,i+1});
            t[65535+a].F++;
            t[65535+a].S+=a;
        }
    }
    build();
    construct();
    a = 1;
    b = arr[1].size();
    c = arr[2].size();
    ll ans = 1e18;
    int sol = -1;
    for(int i=0;i<=min(k,(ll)arr[3].size());i++){
        if(2*k-i>m){
            continue;
        }
        if(arr[3].size()>=i && arr[1].size()>=k-i && arr[2].size()>=k-i){
            while(i>=a){
                sub(arr[3][a-1].F);
                a++;
            }
            while(k-i<b){
                add(arr[1][b-1].F);
                b--;
            }
            while(k-i<c){
                add(arr[2][c-1].F);
                c--;
            }
            auto j = query(m-2*k+i);
            if(j.F<m-2*k+i){
                continue;
            }
            if(ans>dp[3][i]+dp[1][k-i]+dp[2][k-i]+j.S){
                sol = i;
            }
            ans = min(ans,dp[3][i]+dp[1][k-i]+dp[2][k-i]+j.S);
        }
    }
    if(ans!=1e18){
        cout<<ans<<"\n";
    }else{
        cout<<-1<<"\n";
        return;
    } 
    vector<pii>ms;
    for(int i=0;i<sol;i++){
        cout<<arr[3][i].S<<" ";
    }
    for(int i=0;i<k-sol;i++){
        cout<<arr[2][i].S<<" "<<arr[1][i].S<<" ";
    }
    for(int i = sol;i<arr[3].size();i++){
        ms.push_back(arr[3][i]);
    }
    for(int i=k-sol;i<arr[1].size();i++){
        ms.push_back(arr[1][i]);
    }
    for(int i=k-sol;i<arr[2].size();i++){
        ms.push_back(arr[2][i]);
    }
    for(auto i:arr[0]){
        ms.push_back(i);
    }
    sort(ms.begin(),ms.end());
    for(int i=0;i<m-2*k+sol;i++){
        cout<<ms[i].S<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}