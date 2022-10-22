#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,a[N*N][3],shift[3],order[3],b[N*N][3],ans[N][N];
char op[M+1];
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(m);
		F(i,0,n)F(j,0,n)
		{
			int k;read(k);--k;
			a[i*n+j][0]=i;
			a[i*n+j][1]=j;
			a[i*n+j][2]=k;
		}
		scanf("%s",op);
		shift[0]=shift[1]=shift[2]=0;
		order[0]=0;order[1]=1;order[2]=2;
		F(i,0,m)
		{
			if(op[i]=='D')shift[order[0]]=(shift[order[0]]+1)%n;
			if(op[i]=='U')shift[order[0]]=(shift[order[0]]-1+n)%n;
			if(op[i]=='R')shift[order[1]]=(shift[order[1]]+1)%n;
			if(op[i]=='L')shift[order[1]]=(shift[order[1]]-1+n)%n;
			if(op[i]=='C')order[0]^=order[2]^=order[0]^=order[2];
			if(op[i]=='I')order[1]^=order[2]^=order[1]^=order[2];
		}
		F(k,0,3)F(i,0,n*n)b[i][k]=(a[i][order[k]]+shift[order[k]])%n;
		F(i,0,n*n)ans[b[i][0]][b[i][1]]=b[i][2];
		F(i,0,n)
		{
			F(j,0,n)printf("%d ",ans[i][j]+1);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}