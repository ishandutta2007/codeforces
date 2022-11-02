//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=50005;int n,Q,tt,wh[N],wt,rs[225][225];char ch[N];
map<string,int>id;vector<int>pos[475258];int ln[475258],wd[475258];
inline void New(string s,int w,int l) {pos[id[s]?id[s]:id[s]=++tt].push_back(w),(id[s]==tt?ln[tt]=l:0);}
inline int solvenm(int u,int v)
{
	int rs=1e9;for(size_t i=0,j=0;i<pos[u].size();i++)
	{
		while(j<pos[v].size()&&pos[v][j]<pos[u][i]) j++;
		if(j) rs=min(rs,pos[u][i]-pos[v][j-1]+ln[u]);
		if(j!=pos[v].size()) rs=min(rs,pos[v][j]-pos[u][i]+ln[v]);
	}return rs;
}
inline int solvelog(int u,int v)
{
	int rs=1e9;for(size_t i=0;i<pos[u].size();i++)
	{
		size_t w=lower_bound(pos[v].begin(),pos[v].end(),pos[u][i])-pos[v].begin();
		if(w!=pos[v].size()) rs=min(rs,pos[v][w]-pos[u][i]+ln[v]);
		if(w) rs=min(rs,pos[u][i]-pos[v][w-1]+ln[u]);
	}return rs;
}
inline int query(string u,string v)
{
	int U=id[u],V=id[v];if(!U||!V) return -1;else if(u.size()>v.size()) swap(u,v),swap(U,V);
	for(size_t i=0;i+u.size()<=v.size();i++) if(v.substr(i,u.size())==u) return ln[V];
	if(wd[U]&&wd[V]) return rs[wd[U]][wd[V]];else if(!wd[U]&&!wd[V]) return solvenm(U,V);else return solvelog(U,V);
}
inline string sub(int l,int r) {string s="";for(int i=l;i<=r;i++) s=s+ch[i];return s;}
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);const int B=sqrt(n);
	for(int i=1;i<=n;i++) New(sub(i,i),i,1);
	for(int i=1;i<n;i++) New(sub(i,i+1),i,2);
	for(int i=1;i+1<n;i++) New(sub(i,i+2),i,3);
	for(int i=1;i+2<n;i++) New(sub(i,i+3),i,4);
	for(int i=1;i<=tt;i++) if((int)pos[i].size()>=B) wh[++wt]=i,wd[i]=wt;
	for(int i=1;i<=wt;i++) for(int j=i+1;j<=wt;j++) rs[i][j]=rs[j][i]=solvenm(wh[i],wh[j]);
	read(Q);for(string s,t;Q--;) cin>>s>>t,printf("%d\n",query(s,t));
	return 0;
}