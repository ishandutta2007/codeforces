#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
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
    ll n,m,a,b,c,d;cin>>n>>m;
    vector<pair<pii,ll>>s;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        s.push_back({{a+1,a+b},(100-d)});
        s.push_back({{a-b,a-1},(100-c)});
    }
    sort(s.begin(),s.end());
    pii arr[m];
    for(int i=0;i<m;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+m);
    long double ans = 0.0;
    long double cur = 1.0000;
    int j = 0;
    ll oma [101]{0};
    multiset<pair<ll,ll>>ms;
    for(int i=0;i<m;i++){
        while(j<s.size() && s[j].first.first<=arr[i].first){
            ms.insert({s[j].first.second,s[j].second});
            oma[s[j].second]++;
            j++;
        }
        while(ms.size()>0 && (*ms.begin()).first<arr[i].first){
            oma[(*ms.begin()).second]--;
            ms.erase(ms.begin());
        }
        cur=1.0;
        for(int i=0;i<=100;i++){
            if(oma[i]!=0)
                cur*=pow(i*0.01,oma[i]);
        }
        ans+=cur*arr[i].second;
    }
    cout<<setprecision(26)<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}