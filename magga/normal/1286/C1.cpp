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
vector<multiset<string>> query(int l,int r,int a){
    vector<multiset<string>>ret(a+1);
    if(l>r){
        return ret;
    }
    cout<<"? "<<l<<" "<<r<<"\n";
    cout.flush();
    ll n = r-l+1;
    string s;
    for(int i=0;i<(n*(n+1))/2;i++){
        cin>>s;
        sort(s.begin(),s.end());
        ret[s.size()].insert(s);
    }   
    return ret;
}
void answer(string s){
    cout<<"! "<<s<<"\n";
    cout.flush();
}
void solve(){
    ll n;cin>>n;
    auto i = query(1,n,n);
    auto j = query(2,n,n);
    string ans;
    map<char,int>a,b;
    for(int p=1;p<=n;p++){
        string excess;
        for(auto k:i[p]){
            if(j[p].count(k)!=i[p].count(k)){
                excess = k;
                break;
            }   
        }
        b.clear();
        for(auto i:excess){
            b[i]++;
        }
        for(auto i:b){
            if(i.S!=a[i.F]){
                ans+=i.F;
                a[i.F]++;
                break;
            }
        }
    }
    answer(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}