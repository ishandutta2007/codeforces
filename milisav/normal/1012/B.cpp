#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;
vector<int> r[200002];
vector<int> c[200002];
vector<int> a[200002];
bool o[200002];
void dfs(int u) {
	o[u]=true;
	for(int i=0;i<a[u].size();i++) {
		if(!o[a[u][i]]) dfs(a[u][i]);
	}
}
int main()
{
	int u,v,p=0,q=0;
	scanf("%d %d",&n,&m);
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%d %d",&u,&v);
		r[u].push_back(v);
		c[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(r[i].size()==0) p++;
	for(int i=1;i<=m;i++) if(c[i].size()==0) q++;
	u=-1,v=-1;
	int t;
	for(int i=1;i<=n;i++) sort(r[i].begin(),r[i].end());
	for(int i=1;i<=m;i++) sort(c[i].begin(),c[i].end());
	for(int i=1;i<=m;i++) {
		o[i]=false;
		a[i].clear();
	}
	for(int i=1;i<=n;i++) {
		t=r[i].size();
		for(int j=0;j<t-1;j++) {
			a[r[i][j]].push_back(r[i][j+1]);
			a[r[i][j+1]].push_back(r[i][j]);
		}
	}
	for(int i=1;i<=m;i++) {
		if(!o[i]) {
			u++;
			dfs(i);
		}
	}
	//cout<<u<<endl;
	for(int i=1;i<=n;i++) {
		o[i]=false;
		a[i].clear();
	}
	//cout<<"?"<<endl;
	for(int i=1;i<=m;i++) {
		t=c[i].size();
		//cout<<i<<" "<<c[i].size()<<endl;
		for(int j=0;j<t-1;j++) {
			//cout<<c[i][j]<<" "<<c[i][j+1]<<endl;
			a[c[i][j]].push_back(c[i][j+1]);
			a[c[i][j+1]].push_back(c[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		if(!o[i]) {
			v++;
			//cout<<a[i].size()<<endl;
			dfs(i);
		}
	}
	//cout<<v<<endl;
	printf("%d",p+q+min(u-q,v-p));
	return 0;
}