#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=405;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,m,a[N][N],s[N][N],c[N],b[N],tmp[N];
char t[N][N];
int main()
{
	read(T);
	while(T--)
	{
		int ans;
		read(n);read(m);
		ans=n*m;
		F(i,0,n)scanf("%s",t[i]);
		F(i,0,n)F(j,0,m)a[i][j]=t[i][j]-'0';
		F(i,0,n)F(j,0,m)s[i][j+1]=s[i][j]+a[i][j];
		F(i,0,m)F(j,i+3,m)
		{
			int sum=0,mink=-1,all=0;
			F(k,0,n)c[k]=s[k][j]-s[k][i+1]+1-a[k][i]+1-a[k][j];
			F(k,0,n)b[k]=(j-i-1)-(s[k][j]-s[k][i+1]);
			for(int k=n-1;~k;--k)
			{
				if(k+4<n)
				{
					int kk=k+4;
					sum-=c[kk];
					tmp[kk]=sum+b[kk];
					if(!~mink||tmp[mink]>tmp[kk])mink=kk;
				}
				if(~mink)ans=min(ans,all+b[k]+tmp[mink]);
				all+=c[k];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}