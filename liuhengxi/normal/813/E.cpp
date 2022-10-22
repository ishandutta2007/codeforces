#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=5e2+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p,a[N],m,nm,c,s[M][N],t[N],b[M][M],q,z[N];
int main()
{
	int last=0;
	read(n);read(p);
	m=sqrt(n);
	if(m<1)m=1;if(m>n)m=n;
	F(i,0,n)read(a[i]),--a[i];
	F(i,0,n)if(a[i]>c)c=a[i];
	++c;
	nm=(n+m-1)/m;
	F(i,0,nm)
	{
		F(j,0,c)s[i+1][j]=s[i][j];
		F(j,i*m,i*m+m<n?i*m+m:n)++s[i+1][a[j]];
	}
	F(i,0,nm)
	{
		F(j,0,c)t[j]=0;
		F(j,i,nm)
		{
			if(j!=i)b[i][j]=b[i][j-1];
			F(k,j*m,j*m+m<n?j*m+m:n)if(t[a[k]]<p)++t[a[k]],++b[i][j];
		}
	}
	F(i,0,c)z[i]=-1;
	read(q);
	while(q--)
	{
		int x,y,l,r,u,v,ans=0;
		read(x);read(y);
		l=(x+last)%n;r=(y+last)%n;
		if(l>r)l^=r^=l^=r;
		x=(l+m-1)/m*m;y=r/m*m;
		u=x/m;v=y/m;
		if(u>=v)
		{
			F(i,l,r+1)
			{
				if(z[a[i]]!=q)z[a[i]]=q,t[a[i]]=0;
				if(t[a[i]]<p)++t[a[i]],++ans;
			}
		}
		else
		{
			ans=b[u][v-1];
			F(i,l,x)
			{
				if(z[a[i]]!=q)z[a[i]]=q,t[a[i]]=s[v][a[i]]-s[u][a[i]];
				if(t[a[i]]<p)++t[a[i]],++ans;
			}
			F(i,y,r+1)
			{
				if(z[a[i]]!=q)z[a[i]]=q,t[a[i]]=s[v][a[i]]-s[u][a[i]];
				if(t[a[i]]<p)++t[a[i]],++ans;
			}
		}
		printf("%d\n",last=ans);
	}
	return 0;
}