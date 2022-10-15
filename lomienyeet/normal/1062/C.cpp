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
    int n,q;
    string s;
    cin>>n>>q>>s;
    int ps[n+1]={};
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+(s[i-1]=='1');
    while(q--){ // fuck yes!!! big mod template have use now
        int l,r;
        cin>>l>>r;
        int v=ps[r]-ps[l-1],cao=r-l+1-v;
        cout<<((bm(2,v)-1)*bm(2,cao))%mod<<"\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)orz_73();
}