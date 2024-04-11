#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;


int n,q;
int a[N];
int vis[N]; 
bool check(int k){
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;++i)
		if(a[i]<=q)
			vis[i]=1,--k;
	if(k<=0)return 1;
	for(int i=n;i;--i){
		if(!vis[i])vis[i]=1,--k;
		if(!k)break;
	}
	for(int i=1,j=q;i<=n;++i)
		if(vis[i]){
			if(j<=0)return 0;
			if(a[i]>j)--j;
		}
	return true; 
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=q,r=n,res=q;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))res=mid,l=mid+1;
		else r=mid-1;
	}
	check(res);
	for(int i=1;i<=n;i++)
		cout<<vis[i];cout<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}