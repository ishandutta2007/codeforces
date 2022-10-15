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
    // LOL I LITERALLY SAW THI SPROBLEM ALR
    int a,b,q;
    cin>>a>>b>>q; // but then i havent thought of the sol yet, i just read it
    int x=a*b/__gcd(a,b),dp[x];
    dp[0]=0;
    for(int i=1;i<x;i++){
        dp[i]=dp[i-1];
        if(((i%a)%b)!=((i%b)%a))dp[i]++;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ql=(l-1)/x,qql=(l-1)%x,s=dp[x-1]*ql+dp[qql];
        int qr=r/x,qqr=r%x,s2=dp[x-1]*qr+dp[qqr];
        cout<<s2-s<<" ";
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