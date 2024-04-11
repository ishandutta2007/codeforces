/*input
3
110
011
100
100
011
100
100


*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll=long long;
using ld=long double;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()),c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll maxn=2e3+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
int arr[maxn][maxn];
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    REP(i,n){
        string s;
        cin>>s;
        REP(j,n){
            arr[i][j]=(s[j]=='1');
        }
    }
    REP(i,n){
        string s;
        cin>>s;
        REP(j,n){
            if(s[j]=='1') arr[i][j]^=1;
        }
    }
    string s;
    cin>>s;
    int lst=-1;
    REP(i,n){
        if(s[i]=='1'){
            lst=i;
            break;
        }
    }
    vector<pair<string,int>> ans;
    REP(i,n){
        REP(j,n){
            if(!arr[i][j]){
                continue;
            }
            //cout<<i<<' '<<j<<'\n';
            if(lst==j){
                ans.pb({"row ",i});
                REP(k,n){
                    arr[i][k]^=(s[k]-'0');
                }
            }
            else if(lst==i){
                ans.pb({"col ",j});
                REP(k,n) arr[k][j]^=(s[k]-'0');
            }
            else{
                cout<<-1;
                return 0; 
            }
        }
    }
    cout<<sz(ans)<<'\n';
    for(auto x:ans) cout<<x.f<<x.s<<'\n';
}