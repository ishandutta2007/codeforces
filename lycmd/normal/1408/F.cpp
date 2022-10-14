#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
int const N=2333333;
int n,tot,x[N],y[N];
void solve(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	for(int i=l;i<=mid;i++)
		x[++tot]=i,y[tot]=i+mid-l+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int t=n;
	while(t>lowbit(t))t^=lowbit(t);
	solve(1,t),solve(n-t+1,n);
	cout<<tot<<"\n";
	for(int i=1;i<=tot;i++)
		cout<<x[i]<<" "<<y[i]<<"\n";
}