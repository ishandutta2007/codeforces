#include <bits/stdc++.h>
#include <bits/extc++.h> // comment this line if cpp 20, use other two lines instead
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
void eat(){
    // have mercy on me pls :(
    int w,h,n;
    cin>>w>>h>>n;
    set<int> vert,hori;
    multiset<int> vv,hh;
    hori.insert(0);
    hori.insert(w);
    hh.insert(w);
    vv.insert(h);
    vert.insert(0);
    vert.insert(h);
    while(n--){
        char c;int x;
        cin>>c>>x;
        if(c=='H'){
            auto fuck=vert.upper_bound(x);
            int r=*fuck,l=*(--fuck);
            vv.erase(vv.lower_bound(r-l));
            vv.insert(x-l);
            vv.insert(r-x);
            vert.insert(x);
        }
        else{
            auto fuck=hori.upper_bound(x);
            int r=*fuck,l=*(--fuck);
            hh.erase(hh.lower_bound(r-l));
            hh.insert(x-l);
            hh.insert(r-x);
            hori.insert(x);
        }
        auto f=(--vv.end()),g=(--hh.end());
        cout<<(*f)*(*g)<<"\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}