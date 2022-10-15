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
void yes(){cout<<"Yes\n";}
void no(){cout<<"No\n";}
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
const int mxN=2e3+5e2+5;
int bit[mxN<<1][mxN<<1],arr[mxN][mxN];
void upd(int x,int y,int v){
    for(;x<mxN;x+=x&-x){
        for(int i=y;i<mxN;i+=i&-i)bit[x][i]+=v;
    }
}
int qry(int x,int y){
    int ans=0;
    for(;x;x-=x&-x){
        for(int i=y;i;i-=i&-i)ans+=bit[x][i];
    }
    return ans;
}
void eat(){
    int n,m,q;
    cin>>n>>m>>q;
    while(q--){
        int op,a,b,c,d;
        cin>>op>>a>>b>>c>>d;
        if(op==3){
            int x=qry(a-1,b-1),y=qry(c-1,d-1);
            if(x==y)yes();
            else no();
        }
        else{
            if(op==1)arr[a][b]=(rand()+1)*(rand()+1);
            int qq=(op==1?arr[a][b]:-arr[a][b]);
            upd(a-1,b-1,qq);
            upd(a-1,d,-qq);
            upd(c,b-1,-qq);
            upd(c,d,qq);
        }
    }
    return;
}
signed main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}