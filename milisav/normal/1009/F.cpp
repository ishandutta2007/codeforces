#include<bits/stdc++.h>
using namespace std;
struct dubine
{
	dubine* n;
	int s;
	dubine(int sx,dubine* nx) {
		s=sx;
		n=nx;
	}
};
dubine* d[2000001];
int o[2000001];
int r[2000001];
int p[2000001];
int rd[2000001];
int ch[2000001];
int st=1000000;
int n;
vector<int> a[2000001];
dubine* b;
dubine* c;
void dfs(int u)
{
	int v,g;
	ch[u]=1;
	int mc=-1;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i];
		if(rd[v]>=rd[u]+1) {
			rd[v]=rd[u]+1;
			dfs(v);
			ch[u]+=ch[v];
			if(mc==-1 || ch[v]>ch[mc]) mc=v;
		}
	}
	if(mc==-1) {
		ch[u]=1;
		d[u]=new dubine(1,nullptr);
		o[u]=1;
		//d[p[u]].insert(d[p[u]].begin(),1);
		return;
	}
	p[u]=p[mc];
	g=p[u];
	o[u]=1;
	if(o[mc]>1) {
		r[u]=r[mc]+1;
		o[u]=o[mc];
	}
	else r[u]=0;
	b=new dubine(1,d[g]);
	d[g]=b;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i];
		if(rd[v]==rd[u]+1 && v!=mc) {
			c=d[p[v]];
			int j=0;
			b=d[g];
			while(c!=nullptr) {
				if(b->n==nullptr) {
					b->n=new dubine(c->s,nullptr);
				}
				else b->n->s+=c->s;
				b=b->n;
				if(b->s>o[u] || (b->s==o[u] && j+1<r[u])) {
					r[u]=j+1;
					o[u]=b->s;
				}
				c=c->n;
				j++;
			}
		}
	}
	/*b=d[g];
	cout<<u<<"   "<<o[u]<<endl;
	while(b!=nullptr) {
		cout<<b->s<<" ";
		b=b->n;
	}
	cout<<endl;
	/*cout<<u<<endl;
	for(int i=0;i<d[g].size();i++) cout<<d[g][i]<<" ";
	cout<<endl;*/
}
int main()
{
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++) {
		p[i+1]=i+1;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		rd[i+1]=n+1;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(0);
	for(int i=0;i<n;i++) printf("%d\n",r[i]);
	return 0;
}