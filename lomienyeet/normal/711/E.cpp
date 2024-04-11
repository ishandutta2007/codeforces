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
    // nt so hard ( )
    // someone pls help :v
    int n,k;
    cin>>n>>k;
    if(n<=60&&k>(1ll<<n)){
        cout<<"1 1\n";
        return;
    }
    int tot=1,qwq=1000003,pp=bm(2,n%(qwq-1),qwq),inv=bm(pp,qwq-2,qwq);
    for(int i=0;i<k&&tot;i++){
        int cur=((pp-i)%qwq+qwq)%qwq;
        (tot*=cur)%=qwq;
    }
    int aaa=0,z=2,b=1;
    while(z<k){
        aaa+=k/z;
        if(k%z)aaa++;
        z<<=1;
        b++;
    }
    (aaa+=(n-b+1))%=(qwq-1);
    int po=((n%(qwq-1))*(k%(qwq-1)))%(qwq-1),owo=bm(2,po,qwq);
    pp=bm(2,aaa,qwq),inv=bm(pp,qwq-2,qwq);
    (tot*=inv)%=qwq;
    (owo*=inv)%=qwq;
    tot=(owo-tot+qwq)%qwq;
    cout<<tot<<" "<<owo<<"\n"; // :D
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)orz_73();
}