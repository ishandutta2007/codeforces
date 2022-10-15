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
    /*
    
    
    */
    int n;
    cin>>n;
    int a[n],b[n];
    map<int,int> freq;
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    for(int i=0;i<n;i++)cin>>b[i];
    int ans=0;
    map<int,bool> go;
    for(int i=0;i<n;i++){
        if(go[a[i]]||freq[a[i]]==1)continue;
        vector<int> v;
        for(int j=0;j<n;j++){
            if(go[a[j]])continue;
            if((a[i]&a[j])==a[j]){
                ans+=b[j];
                v.push_back(a[j]);
            }
        }
        for(auto j:v)go[j]=1;
        go[a[i]]=1;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}