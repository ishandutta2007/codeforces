#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5;
int n,a[N],b[N];
char res[N];
int main()
{
	read(n);
	F(i,0,n)a[i]=i+1;
	while(n>3)
	{
		int m[5]={0,n>>2,n>>1,3*n>>2,n};
		printf("? %d ",m[2]-m[0]);
		F(i,m[0],m[2])printf("%d ",a[i]);
		puts("");
		printf("? %d ",m[1]-m[0]+m[3]-m[2]);
		F(i,m[0],m[1])printf("%d ",a[i]);
		F(i,m[2],m[3])printf("%d ",a[i]);
		puts("");
		fflush(stdout);
		scanf("%s",res);
		int ans=res[0]=='Y';
		scanf("%s",res);
		(ans<<=1)|=res[0]=='Y';
		F(i,m[ans],m[ans+1])a[i]=-1;
		int nn=0;
		F(i,0,n)if(~a[i])b[nn++]=a[i];
		n=nn;
		F(i,0,n)a[i]=b[i];
	}
	if(n==3)
	{
		printf("? 1 %d\n",a[0]);fflush(stdout);
		scanf("%s",res);
		int ban=0;
		if(res[0]=='Y')
		{
			printf("? 1 %d\n",a[1]);fflush(stdout);
			scanf("%s",res);
			if(res[0]=='Y')ban=2;
			else ban=1;
		}
		else
		{
			printf("? 1 %d\n",a[0]);fflush(stdout);
			scanf("%s",res);
			if(res[0]=='Y')
			{
				printf("? 1 %d\n",a[1]);fflush(stdout);
				scanf("%s",res);
				if(res[0]=='Y')ban=2;
				else ban=1;
			}
		}
		printf("! %d\n",a[(ban+1)%3]);
		fflush(stdout);
		scanf("%s",res);
		if(res[1]=='(')printf("! %d\n",a[(ban+2)%3]);
	}
	else if(n==2)
	{
		printf("! %d\n",a[0]);
		fflush(stdout);
		scanf("%s",res);
		if(res[1]=='(')printf("! %d\n",a[1]);
	}
	else printf("! %d\n",a[0]);
	return 0;
}