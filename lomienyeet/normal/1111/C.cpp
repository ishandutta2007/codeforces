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
const int mxN=1e5+5; // oh my god.. i am fucking stupid
int n,k,a,b,arr[mxN];
int fuck(int l,int r){
    if(arr[0]>r||arr[k-1]<l)return 0;
    int lb=0,ub=k-1;
    while(lb<ub){
        int mid=(lb+ub)>>1;
        if(arr[mid]>=l)ub=mid;
        else lb=mid+1;
    }
    int ee=lb,qq;
    lb=0,ub=k-1;
    while(lb<ub){
        int mid=(lb+ub+1)>>1;
        if(arr[mid]<=r)lb=mid;
        else ub=mid-1;
    }
    qq=lb;
    return max(qq-ee+1,0ll);
}
int qry(int l,int r){
    int cur=fuck(l,r);
    if(!cur)return a;
    int qwq=b*(r-l+1)*cur;
    if(l==r)return qwq;
    int mid=(l+r)>>1;
    return min(qwq,qry(l,mid)+qry(mid+1,r));
}
void eat(){
    cin>>n>>k>>a>>b;
    for(int i=0;i<k;i++)cin>>arr[i];
    sort(arr,arr+k);
    cout<<qry(1,(1<<n))<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}