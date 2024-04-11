#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,cur[2],t[2],mn[2],mx[2],a[N],l[N][2],r[N][2],pre[N][2];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>l[i][0]>>r[i][0]>>l[i][1]>>r[i][1];
	for(int i=0;i<2;i++)
		cur[i]=1,t[i]=n+1,mx[i]=m;
	for(int i=n;i;i--){
		for(int j=0;j<2;j++)
			cur[j]&=l[i][j]<=a[i]&&a[i]<=r[i][j],
			mn[j]=max(mn[j],l[i][!j]),
			mx[j]=min(mx[j],r[i][!j]);
		int t0=cur[0]&&mn[0]<=a[i-1]&&a[i-1]<=mx[0],
			t1=cur[1]&&mn[1]<=a[i-1]&&a[i-1]<=mx[1];
		if(t0)pre[i][0]=t[1];
		if(t1)pre[i][1]=t[0];
		if(t0)t[0]=i,cur[1]=1,mn[1]=0,mx[1]=m;
		if(t1)t[1]=i,cur[0]=1,mn[0]=0,mx[0]=m;
	}
	if(t[0]>1&&t[1]>1)
		cout<<"No\n",exit(0);
	cout<<"Yes\n";
	for(int i=1,op=t[0]>1;i<=n;i=pre[i][op],op^=1)
		for(int j=i;j<pre[i][op];j++)
			cout<<op<<" ";
	cout<<"\n";
}