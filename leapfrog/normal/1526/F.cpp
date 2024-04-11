//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,rs[1000005];
inline int qry(int x,int y,int z) {printf("? %d %d %d\n",x,y,z),fflush(stdout);int q;return read(q),q;}
inline void solve()
{
	read(n);int x=0,y;for(int i=1;i<=13&&!x;i++) for(int j=i+1;j<=13&&!x;j++)
		for(int k=j+1;k<=13&&!x;k++) if(qry(i,j,k)<=(n-4)/6) x=i,y=j;
	map<int,vector<int> >mp;for(int i=1;i<=n;i++) if(i^x&&i^y) mp[-qry(x,y,i)].push_back(i);
	int vl=(*mp.begin()).first;if((int)mp[vl+1].size()>=2)
	if(qry(mp[vl][0],mp[vl+1][0],x)>qry(mp[vl][0],mp[vl+1][1],x)) swap(mp[vl+1][0],mp[vl+1][1]);
	int p=mp[vl][0],q=mp[vl+1][0];rs[p]=1,rs[q]=2;
	for(int i=1;i<=n;i++) if(i!=p&&i!=q) rs[i]=qry(p,q,i)+2;
	if(rs[1]>rs[2]) for(int i=1;i<=n;i++) rs[i]=n-rs[i]+1;
	printf("! ");for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	fflush(stdout);int FUCKCODEFORCES;read(FUCKCODEFORCES);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}