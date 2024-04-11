//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,tw[3005],a[3005],v[3005][3005];
inline int qry(int x,int y)
{
	if(~v[x][y]) return v[x][y];
	cout<<"? "<<x+1<<" "<<y+1<<endl,fflush(stdout);
	int Q;read(Q);return v[x][y]=v[y][x]=Q;
}
inline char zero(int x)
{
	int qwq=2047;
	for(int i=60;i;i--)
	{
		int wh=rand()%n;
		while(wh==x) wh=rand()%n;
		qwq&=qry(wh,x);if(!qwq) return 1;
	}
	return 0;
}
int main()
{
	read(n),srand(20050412);
	for(int i=0;i<n;i++) tw[i]=i;
	random_shuffle(tw,tw+n),memset(v,-1,sizeof(v));
	int mn=qry(tw[0],tw[1]),m1=tw[0],m2=tw[1];
	for(int i=2;i<n;i++)
	{
		int x=m1,y=m2,z=tw[i],w1=qry(z,x);
		if(w1<=mn)
		{
			int w2=qry(z,y);
			if(w1<=w2) m2=z,mn=w1;else m1=z,mn=w2;
		}
	}
	if(zero(m2)) m1=m2;
	for(int i=0;i<n;i++) if(m1!=i) a[i]=qry(i,m1);
	printf("! ");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');
	return 0;
}