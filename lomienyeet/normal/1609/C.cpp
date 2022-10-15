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
const int mxN=1e6+5;
bool isp[mxN];
void precompute(){
    isp[0]=isp[1]=0;
    for(int i=2;i<mxN;i++){
        for(int j=i*i;j<mxN;j+=i)isp[j]=0;
    }
}
void orz_73(){
    int n,x,ans=0;
    cin>>n>>x;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        if(isp[arr[i]]){
            int z=0,u=0,l=i,r=i;
            while(r+x<=n&&arr[r+x]==1){
                z++;
                r+=x;
            }
            while(l-x>0&&arr[l-x]==1){
                u++;
                l-=x;
            }
            ans+=(u*z+u+z);
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
    for(int i=0;i<mxN;i++)isp[i]=1;
    precompute();
	while(t--)orz_73();
}