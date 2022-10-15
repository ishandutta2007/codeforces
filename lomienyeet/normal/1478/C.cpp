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
    int arr[n*2+1];
    for(int i=1;i<=2*n;i++)cin>>arr[i];
    sort(arr+1,arr+2*n+1);
    if(arr[1]&1){
        no();
        return;
    }
    for(int i=1;i<=2*n;i+=2){
        if(arr[i]!=arr[i+1]||(i+2<=2*n&&arr[i]==arr[i+2])){
            no();
            return;
        }
    }
    int s=0,v=0;
    for(int i=3;i<=2*n;i+=2){
        if((arr[i]-arr[i-2])%(i-1)){
            no();
            return;
        }
        v+=(arr[i]-arr[i-2])/(i-1)*2;
        s+=v;
    }
    if((s>=arr[1])||((arr[1]-s)%(2*n)))no();
    else yes();
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)orz_73();
}