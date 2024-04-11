#include<bits/stdc++.h>
#define int long long
const int N=400050,P=31;
using namespace std;
using vi=basic_string<int>;

int a[N];
struct sgt{
	#define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    vi s[N];
    vi mrg(vi X,vi Y){
    	int a=X.size(),b=Y.size();
    	vi res;
    	for(int i=0,j=0;i<a||j<b;){
    		if(j==b)res+=X[i++];
    		else if(i==a)res+=Y[j++];
    		else if(X[i]<Y[j])res+=X[i++];
    		else res+=Y[j++];
    		if(res.size()>=P)break;
		}
		return res;
	}
	void build(int k,int l,int r){
		if(l^r){
			build(ls,l,mid);
			build(rs,mid+1,r);
			s[k]=mrg(s[ls],s[rs]);
		}else s[k]={a[l]};
	}
    vi qry(int k,int l,int r,int x,int y){
    	if(l>y||r<x)return {};
    	if(l>=x&&r<=y)return s[k];
    	return mrg(qry(ls,l,mid,x,y),qry(rs,mid+1,r,x,y));
	}
}T;

void solve(){
	vi nw;
	int n,q;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	T.build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		auto X=T.qry(1,1,n,x,y);
//		for(auto i:X)cout<<i<<' '; 
		int res=1e11;
		for(int i=0;i<X.size();i++)
			for(int j=i+1;j<X.size();j++)
				res=min(res,X[i]|X[j]);
		cout<<res<<'\n'; 
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}