#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
//template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
void pau_txdy(){
	int n;
	cin>>n;
    string a,b;
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=1,r=1,ans=0;
    while(l<=n&&r<=n){
        if(a[l]<=b[r]){
            l++;
            r++;
        }
        else{
            ans++;
            r++;
        }
    }
    cout<<ans<<"\n";
    l=1,r=1,ans=0;
    while(l<=n&&r<=n){
        if(a[l]<b[r]){
            l++;
            r++;
            ans++;
        }
        else r++;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)pau_txdy();
}