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
const int N=100005,B=555;deque<int>q[B];
int n,bl[N],L[B],R[B],blt,ti[B][N];
int main()
{
	read(n);int bb=sqrt(n);for(int i=1;i<=n;i++) bl[i]=(i-1)/bb+1;
	for(int i=1;i<=n+1;i++) if(bl[i-1]^bl[i]) {R[blt]=i-1;if(i^(n+1)) L[++blt]=i;}
	for(int i=1,x;i<=n;i++) read(x),q[bl[i]].push_back(x),ti[bl[i]][x]++;
	int Q,rs=0;for(read(Q);Q--;)
	{
		int fg,l,r,k,cl,cr;read(fg,l,r);if(!(fg&1)) read(k);
#ifdef ONLINE_JUDGE
		l=(l+rs-1)%n+1,r=(r+rs-1)%n+1,k=(k+rs-1)%n+1;if(l>r) swap(l,r);
#endif
		cl=bl[l],cr=bl[r];if(!(fg&1))
		{
			rs=0;if(cl==cr) {for(int i=l;i<=r;i++) rs+=q[cl][i-L[cl]]==k;printf("%d\n",rs);continue;}
			for(int i=l;i<=R[cl];i++) rs+=q[cl][i-L[cl]]==k;
			for(int i=L[cr];i<=r;i++) rs+=q[cr][i-L[cr]]==k;
			for(int i=cl+1;i<cr;i++) rs+=ti[i][k];
			printf("%d\n",rs);continue;
		}
		if(cl==cr)
		{
			k=q[cl][r-L[cl]],q[cl].erase(q[cl].begin()+(r-L[cl]));
			q[cl].insert(q[cl].begin()+(l-L[cl]),k);continue;
		}
		for(int i=cl;i<cr;i++) k=q[i].back(),q[i+1].push_front(k),q[i].pop_back(),ti[i][k]--,ti[i+1][k]++;
		k=q[cr][r-L[cr]+1],q[cr].erase(q[cr].begin()+(r-L[cr]+1)),ti[cr][k]--;
		q[cl].insert(q[cl].begin()+(l-L[cl]),k),ti[cl][k]++;
	}return 0;
}