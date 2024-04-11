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
const int mxN=1e5+5;
int st[mxN],en[mxN];
bool cmp(int u,int v){return en[u]<en[v];}
void eat(){
    int n;
    cin>>n;
    int k[n+1];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int maxi=0,s=0;
        for(int j=0,x;j<k[i];j++){
            cin>>x;
            maxi=max(maxi,x-s+1);
            s++;
        }
        st[i]=i;
        en[i]=maxi;
    }
    sort(st+1,st+n+1,cmp);
    int ans=0,s2=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,en[st[i]]-s2);
        s2+=k[st[i]];
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}