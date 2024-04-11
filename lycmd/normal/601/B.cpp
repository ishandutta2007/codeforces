#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,B=23;
int n,q,a[N],b[N],lg[N];
pair<int,int>st[B][N];
void init(){
	for(int i=2;i<=n;i++)
		st[0][i]={b[i],i};
	for(int i=2;i<N;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<B;i++)
		for(int j=2;j<=n-(1<<(i-1));j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
pair<int,int>ask(int l,int r){
	int k=lg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int solve(int l,int r){
	if(l>r)return 0;
	pair<int,int>p=ask(l,r);
	int mid=p.second;
	return b[mid]*(mid-l+1)*(r-mid+1)+solve(l,mid-1)+solve(mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=abs(a[i]-a[i-1]);
	init();
	while(q--){
		int l,r;cin>>l>>r,l++;
		cout<<solve(l,r)<<"\n";
	}
}