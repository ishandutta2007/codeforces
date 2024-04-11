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
    string s;
    cin>>s;
    int go[s.length()];
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')go[i]=i;
        else if(!i)go[i]=-1;
        else go[i]=go[i-1];
    }
    int ans=0;
    for(int i=0;i<s.length();i++){
        int z=0;
        for(int j=i;j>=0&&i-j<20;j--){
            if(s[j]=='0')continue;
            z+=(1<<(i-j));
            if(z<=i-(!j?-1:go[j-1]))ans++;
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
	while(t--)orz_73();
}