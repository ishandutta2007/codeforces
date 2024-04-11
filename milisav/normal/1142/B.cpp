#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int p[500000];
int a[300000];
int s[300000];
int t[300000][20];
int ut[300000];
int ne[300000];
int seg[2000000];
void add(int id,int l,int r,int u) {
	if(l==r) {
		seg[id]=s[u];
		return;
	}
	int mid=(l+r)>>1;
	if(u<=mid) add(id*2+1,l,mid,u);
	else add(id*2+2,mid+1,r,u);
	seg[id]=min(seg[id*2+1],seg[id*2+2]);
}
int query(int id,int l,int r,int x,int y) {
	if(y<l || x>r) return m;
	if(x<=l && r<=y) return seg[id];
	int mid=(l+r)>>1;
	return min(query(id*2+1,l,mid,x,y),query(id*2+2,mid+1,r,x,y));
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++) {
		scanf("%d",&p[i]);
		p[n+i]=p[i];
		ut[i+1]=m;
	}
	for(int i=0;i<n;i++) ne[p[i]]=p[i+1];
	for(int i=0;i<20;i++) t[m][i]=m;
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	for(int i=0;i<5*m;i++) seg[i]=m;
	for(int i=m-1;i>=0;i--) {
		t[i][0]=ut[ne[a[i]]];
		//printf("%d\n",t[i][0]);
		for(int j=1;j<20;j++) t[i][j]=t[t[i][j-1]][j-1];
		int k=n-1;
		int u=i;
		int j=0;
		ut[a[i]]=i;
		while(k>0) {
			if(k&1) 
			{
				//cout<<u<<" "<<t[u][j]<<" "<<j<<endl;
				u=t[u][j];
			}
			k>>=1;
			j++;
		}
		s[i]=u;
		//printf("%d\n",s[i]);
		add(0,0,m-1,i);
	}
	int l,r;
	while(q--) {
		scanf("%d %d",&l,&r);
		if(query(0,0,m-1,l-1,r-1)<=r-1) printf("1");
		else printf("0");
	}
	return 0;
}