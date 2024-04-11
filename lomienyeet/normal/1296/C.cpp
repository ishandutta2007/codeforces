#include <bits/stdc++.h>
// #include <bits/extc++.h> // use if non-cf & non-c++20
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // use if cf & C++20 (iconv.h got deprecated or sth i dont remember)
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
    int n;string s;
    cin>>n>>s;
    map<pair<int,int>,int> mp;
    mp[{0,0}]=1;
    int curx=0,cury=0,lb,ub,ans=1e18;
    bool z=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')curx++;
        else if(s[i]=='U')cury++;
        else if(s[i]=='L')curx--;
        else cury--;
        if(mp[{curx,cury}]){
            z=1;
            if(ans>i+2-mp[{curx,cury}]){
                ans=i+2-mp[{curx,cury}];
                lb=mp[{curx,cury}];
                ub=i+1;
            }
        }
        mp[{curx,cury}]=i+2;
    }
    if(z)cout<<lb<<" "<<ub<<"\n";
    else cout<<"-1\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)eat();
}