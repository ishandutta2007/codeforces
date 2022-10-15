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
void eat(){ // hi pau ! ! !
    int n,ans=1;string s;
    cin>>n>>s;
    int freq=0,freq2=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==s[0])freq++;
        else break;
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==s[s.length()-1])freq2++;
        else break;
    }
    ans+=freq+freq2+(s[0]==s[s.length()-1]?freq*freq2:0);
    cout<<ans%mod2<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}