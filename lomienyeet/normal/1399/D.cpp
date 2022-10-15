#include <bits/stdc++.h>
#include <bits/extc++.h> // comment this line if cpp 20, use other two lines instead
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
    // have mercy on me pls :(
    int n;string s;
    cin>>n>>s;
    // i bet wch cant ac middle q in 10 mins
    // or maybe i am just too stupid to think of a good construction
    queue<int> orz,fai;
    int ans[n],cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(orz.size()){
                auto x=orz.front();
                orz.pop();
                ans[i]=x;
                fai.push(x);
            }
            else{
                cnt++;
                fai.push(cnt);
                ans[i]=cnt;
            }
        }
        else{
            if(fai.size()){
                auto x=fai.front();
                fai.pop();
                ans[i]=x;
                orz.push(x);
            }
            else{
                cnt++;;
                orz.push(cnt);
                ans[i]=cnt;
            }
        }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
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