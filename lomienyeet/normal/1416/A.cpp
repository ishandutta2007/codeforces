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
void eat(){
    int n;
    cin>>n;
    int arr[n+1],ans[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ans[i]=1e18;
    }
    vector<int> fuck[n+1];
    for(int i=1;i<=n;i++)fuck[arr[i]].push_back(i);
    for(int i=1;i<=n;i++){
        if(fuck[i].empty())continue;
        int ptr=0,maxi=-1;
        for(auto j:fuck[i]){
            maxi=max(maxi,j-ptr);
            ptr=j;
        }
        maxi=max(maxi,n-ptr+1);
        if(ans[maxi]==1e18)ans[maxi]=i;
    }
    int diu=1e18;
    for(int i=1;i<=n;i++){
        diu=min(diu,ans[i]);
        if(diu==1e18)cout<<"-1 ";
        else cout<<diu<<" ";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}