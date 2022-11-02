//
#include<bits/stdc++.h>
#define double long double
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct node{int id,tag;double w;bool operator<(node b) const {return w>b.w;}};
struct qwqnd{int id,tag,val;bool operator<(qwqnd b) const {return val>b.val;}};
int k,n,m;long long vl[200005];vector<node>w[200005],ed,fc;vector<qwqnd>a[200005];qwqnd mxn[200005];
inline char CMP(node a,node b) {return a.tag<b.tag;}
int main()
{
	read(k),read(n),read(m);
	for(int i=1;i<=k;i++) read(vl[i]);
	for(int i=1,x,y,fg;i<=n;i++)
	{
		read(fg),read(x),read(y);
		if(fg==2) a[x].push_back((qwqnd){i,2,y});
		else if(fg==3) w[x].push_back((node){i,3,1.0*y});
		else if(mxn[x].val<y) mxn[x]=(qwqnd){i,1,y};
	}
	for(int i=1;i<=k;i++) if(mxn[i].val>vl[i]) a[i].push_back((qwqnd){mxn[i].id,1,mxn[i].val-vl[i]});
	for(int i=1;i<=k;i++) sort(a[i].begin(),a[i].end());
	for(int i=1;i<=k;i++) for(int j=0;j<(int)a[i].size();j++)
		w[i].push_back((node){a[i][j].id,a[i][j].tag,1+1.0*a[i][j].val/vl[i]}),vl[i]+=a[i][j].val;
	for(int i=1;i<=k;i++) for(int j=0;j<(int)w[i].size();j++) ed.push_back(w[i][j]);
	sort(ed.begin(),ed.end());int mx;
	for(mx=0;mx<m&&mx<(int)ed.size()&&ed[mx].w>1;mx++);
	printf("%d\n",mx);for(int i=0;i<mx;i++) fc.push_back(ed[i]);
	sort(fc.begin(),fc.end(),CMP);for(int i=0;i<mx;i++) printf("%d%c",fc[i].id,i==mx-1?'\n':' ');
	return 0;
}