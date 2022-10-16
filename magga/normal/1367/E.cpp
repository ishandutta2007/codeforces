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
vector<int>ms;
ll check(int n){
    priority_queue<ll>st;
    priority_queue<pair<ll,pii>>pq;
    for(auto i:ms){
        st.push(i);
    }
    auto i = st.top();
    pq.push({i/2,{i,2}});
    ll ans = i;
    st.pop();
    for(int i=1;i<n;i++){
        auto j = pq.top();
        if(st.size()>0 && st.top()>j.F){
            auto i = st.top();
            ans = st.top();
            st.pop();
            pq.push({i/2,{i,2}});
            continue;
        }
        pq.pop();
        pq.push({(j.S.F)/(j.S.S+1),{j.S.F,j.S.S+1}});
        ans = j.F;
    }
    return ans;
}
void solve(){
    ll n,k;cin>>n>>k;
    map<char,int>m;
    ms.clear();
    string s;cin>>s;
    for(char c:s){
        m[c]++;
    }
    for(auto i:m){
        ms.push_back(i.S);
    }
    ll ans = 0;
    for(int i=1;i<=sqrt(k);i++){
        if(k%i!=0){
            continue;
        }
        ans = max(ans,check(i)*i);
        ans = max(ans,check(k/i)*(k/i));
    }
    cout<<ans<<"\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}