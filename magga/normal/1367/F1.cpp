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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
void pre(){}
void solve(){
    ll n;cin>>n;
    ll d;
    map<int,ordered_set>m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d].insert(i);
    }
    vector<ordered_set>v;
    for(auto &i:m){
        v.push_back(i.S);
    }
    ll ans = 0;
    ll lst = -1;
    ll curr = 0; 
    for(int i=0;i<v.size();i++){
        if(*v[i].find_by_order(0)>lst){
            curr+=v[i].size();
            lst = *v[i].find_by_order(v[i].size()-1);
        }else{
            curr+=v[i].size()-v[i].order_of_key(lst);
            ans = max(ans,curr);
            curr = v[i-1].order_of_key(*v[i].find_by_order(0)) + v[i].size();
            lst = *v[i].find_by_order(v[i].size()-1);
        }
    }
    ans = max(ans,curr);
    cout<<n-ans<<"\n";
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