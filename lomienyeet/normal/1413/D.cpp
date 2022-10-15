#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
void orz_73(){
    int n;
    cin>>n;
    pair<char,int> p[2*n];
    for(int i=0;i<2*n;i++){
        cin>>p[i].ff;
        if(p[i].ff=='-')cin>>p[i].ss;
        else p[i].ss=-1; // no
    }
    stack<int> s;
    vector<int> ans;
    for(int i=2*n-1;i>=0;i--){
        if(p[i].ff=='-'){
            if(s.size()&&s.top()<p[i].ss){
                no();
                return;
            }
            s.push(p[i].ss);
        }
        else{
            if(s.empty()){
                no();
                return;
            }
            ans.push_back(s.top());
            s.pop();
        }
    }
    yes();
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)orz_73();
}