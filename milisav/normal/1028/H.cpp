#include<bits/stdc++.h>
using namespace std;
int n;
int q;
int ans[200000][20];
int dv[6000000];
vector<int> p[200000];
int a[200000];
vector<pair<int,int> > z[6000000];
int seg[1000000][20];
void update(int ind,int l,int r,int x,int y,int u)
{
	//cout<<x<<" "<<y<<" "<<v<<endl;
	int i=ind;
	if(l==r) {
		seg[ind][u]=max(seg[ind][u],x);
		return;
	}
	i=(l+r)>>1;
	if(y>=i+1) update(2*ind+2,i+1,r,x,y,u);
	else update(2*ind+1,l,i,x,y,u);
	seg[ind][u]=max(seg[ind][u],max(seg[2*ind+1][u],seg[2*ind+2][u]));
}
int query(int ind,int l,int r,int x,int y,int v)
{
	if(l==r) {
		return seg[ind][v];
	}
	if(x<=l && y>=r) {
		return seg[ind][v];
	}
	int m=(l+r)>>1;
	if(x>=m+1) return query(2*ind+2,m+1,r,x,y,v);
	if(y<=m) return query(2*ind+1,l,m,x,y,v);
	return max(query(2*ind+1,l,m,x,y,v),query(2*ind+2,m+1,r,x,y,v));
}
int main()
{
	//n=q=180000;
	//srand(time(NULL));
	scanf("%d %d",&n,&q);
	int l=1,u,r;
	for(int i=0;i<1000000;i++) {
		for(int j=0;j<20;j++) seg[i][j]=-1;
	}
	for(int i=0;i<n;i++) {
		//a[i]=(rand()*rand())%5000000;
		//cout<<a[i]<<endl;
		scanf("%d",&a[i]);
		for(int j=2;j*j<=a[i];j++) {
			while(a[i]%(j*j)==0) {
				a[i]/=(j*j);
			}
		}
		for(int j=1;j*j<=a[i];j++) {
			if(a[i]%j==0) {
				p[i].push_back(j);
				if(j*j!=a[i]) p[i].push_back(a[i]/j);
			}
		}
	}
	for(int i=2;i<6000000;i++) {
		if(dv[i]==0) {
			for(int j=i;j<6000000;j+=i) dv[j]++;
		}
	}
	for(int j=0;j<20;j++) ans[0][j]=-1;
	for(int i=0;i<n;i++) {
		if(i>0) {
			for(int j=0;j<20;j++) ans[i][j]=ans[i-1][j];
		}
		//cout<<a[i]<<" "<<dv[a[i]]<<endl;
		for(int j=0;j<p[i].size();j++) {
			//cout<<p[i][j]<<" ";
			//if(z[p[i][j]].size()>10) cout<<z[p[i][j]].size()<<endl;
			for(int k=0;k<z[p[i][j]].size();k++) {
				l=z[p[i][j]][k].first;
				u=z[p[i][j]][k].second+dv[a[i]];
				ans[i][u]=max(ans[i][u],l);
				//cout<<l<<" "<<i<<" "<<u<<endl;
				//update(0,0,n-1,l,i,u);
			}
		}
		//cout<<endl;
		for(int j=0;j<p[i].size();j++) {
			while(z[p[i][j]].size()!=0 && z[p[i][j]][z[p[i][j]].size()-1].second>=dv[a[i]]-2*dv[p[i][j]]) z[p[i][j]].pop_back();
			z[p[i][j]].push_back(make_pair(i,dv[a[i]]-2*dv[p[i][j]]));
		}
	}
	int v=20;
	int x=0;
	int y=19;
	int m;
	while(q--) {
		scanf("%d %d",&l,&r);
		l--;
		r--;
		for(int i=0;i<20;i++) {
			if(ans[r][i]>=l) {
				v=i;
				i=20;
			}
		}
		printf("%d\n",v);
		//printf("%d\n",query(0,0,n-1,l,r));
	}
	return 0;
}