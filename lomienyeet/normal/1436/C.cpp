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
const int mxN=1e3+5;
int fact[mxN];
void calc(){
    fact[0]=1;
    for(int i=1;i<mxN;i++)fact[i]=(fact[i-1]*i)%mod;
}
int npr(int n,int r){
    return (fact[n]*bm(fact[n-r],mod-2))%mod;
}
void eat(){
    int n,x,y;
    cin>>n>>x>>y;
    calc();
    int l=0,r=n,a=0,b=0;
    while(l<r){
        int mid=(l+r)>>1;
        if(mid<y){
            l=mid+1;
            a++;
        }
        else if(mid>y){
            r=mid;
            b++;
        }
        if(mid==y)l=mid+1;
    }    
    cout<<((((npr(x-1,a)%mod)*(npr(n-x,b)%mod))%mod)*fact[n-a-b-1])%mod<<"\n";
    //if(!y)exit(1);
    // actually bs is very orz i cant afford to 3 in a row
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}