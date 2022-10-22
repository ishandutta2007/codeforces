#include<bits/stdc++.h>
using namespace std;
int n;
int v[1000005];
int o[1000005];
int l[1000005];
int m[1000005];
int r[1000005];
int lc[1000005];
int rc[1000005];
vector<int> ind;
vector<int> val;
vector<pair<int,int> > sol;
char s[5];
void dfs(int x) {
	m[x]=-1;
	if(o[x]==4) {
		l[x]=ind.size();
		r[x]=ind.size();
		ind.push_back(x);
		val.push_back(v[x]);
		return;
	}
	if(o[x]==3) {
		dfs(lc[x]);
		l[x]=l[lc[x]];
		r[x]=r[lc[x]];
		v[x]=(!v[lc[x]]);
		return;
	}
	dfs(lc[x]);
	dfs(rc[x]);
	l[x]=l[lc[x]];
	m[x]=r[lc[x]];
	r[x]=r[rc[x]];
	//cout<<x<<" "<<l[x]<<" "<<m[x]<<" "<<r[x]<<endl;
	if(o[x]==2) v[x]=(v[lc[x]]^v[rc[x]]);
	if(o[x]==1) v[x]=(v[lc[x]]|v[rc[x]]);
	if(o[x]==0) v[x]=(v[lc[x]]&v[rc[x]]);
}
void query(int x,bool rev=false) {
	if(o[x]==4) {
		if(rev) val[l[x]]=(v[x]);
		else val[l[x]]=(!v[x]);
		return;
	}
	if(o[x]==3) {
		query(lc[x],!rev);
		return;
	}
	if(o[x]==2) {
		if(v[rc[x]]==0) query(lc[x],rev);
		else query(lc[x],!rev);
		if(v[lc[x]]==0) query(rc[x],rev);
		else query(rc[x],!rev);
		return;
	}
	if(o[x]==1) {
		if(v[rc[x]]==0) query(lc[x],rev);
		else for(int i=l[x];i<=m[x];i++) val[i]=(!rev);
		if(v[lc[x]]==0) query(rc[x],rev);
		else for(int i=m[x]+1;i<=r[x];i++) val[i]=(!rev);
		return;
	}
	if(o[x]==0) {
		if(v[rc[x]]==1) query(lc[x],rev);
		else for(int i=l[x];i<=m[x];i++) val[i]=(rev);
		if(v[lc[x]]==1) query(rc[x],rev);
		else for(int i=m[x]+1;i<=r[x];i++) val[i]=(rev);
		return;
	}
}
int main()
{
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",s);
		if(s[0]=='A') {
			scanf("%d %d",&x,&y);
			lc[i]=x;
			rc[i]=y;
			o[i]=0;
		}
		if(s[0]=='O') {
			scanf("%d %d",&x,&y);
			lc[i]=x;
			rc[i]=y;
			o[i]=1;
		}
		if(s[0]=='X') {
			scanf("%d %d",&x,&y);
			lc[i]=x;
			rc[i]=y;
			o[i]=2;
		}
		if(s[0]=='N') {
			scanf("%d",&x);
			lc[i]=x;
			o[i]=3;
		}
		if(s[0]=='I') {
			scanf("%d",&x);
			v[i]=x;
			lc[i]=-1;
			rc[i]=-1;
			o[i]=4;
		}
	}
	dfs(1);
	//cout<<"OK"<<endl;
	query(1);
	for(int i=0;i<ind.size();i++) sol.push_back(make_pair(ind[i],val[i]));
	sort(sol.begin(),sol.end());
	for(int i=0;i<sol.size();i++) printf("%d",sol[i].second);
	return 0;
}