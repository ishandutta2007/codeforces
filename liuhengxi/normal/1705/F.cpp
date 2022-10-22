#include<cstdio>
#include<cstdlib>
#include<random>
#ifdef LOCAL
#define TEST
#endif
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
constexpr int N=1005;
mt19937 rnd(79774871);
int n,base[N],zero;
#ifdef TEST
int qcnt;
char realans[N];
#endif
void queryinit()
{
	#ifdef TEST
	++qcnt;
	F(i,0,n)zero+=('F'+('T'-'F')*base[i])==realans[i];
	#else
	F(i,0,n)putchar('F'+('T'-'F')*base[i]);
	puts("");fflush(stdout);
	read(zero);
	#endif
	if(zero==n)
	{
		#ifdef TEST
		printf("correct %d\n",qcnt);
		#endif
		exit(0);
	}
}
int query(int *ans)
{
	int k=0,tot=0;
	F(i,0,n)tot+=ans[i];
	#ifdef TEST
	++qcnt;
	F(i,0,n)k+=('F'+('T'-'F')*(ans[i]^base[i]))==realans[i];
	#else
	F(i,0,n)putchar('F'+('T'-'F')*(ans[i]^base[i]));
	puts("");fflush(stdout);
	read(k);
	#endif
	if(k==n)
	{
		#ifdef TEST
		printf("correct %d\n",qcnt);
		#endif
		exit(0);
	}
	return (k-zero+tot)>>1;
}
int ans[N],fa[N],q[N<<2],qf,qr,tmp[N];
int main()
{
	read(n);
	#ifdef TEST
	scanf("%s",realans);
	#endif
	F(i,0,n)base[i]=rnd()&1;
	queryinit();
	F(i,0,n)q[qr++]=i,fa[i]=-1;
	while(qr-qf>=4)
	{
		int a[4];
		F(k,0,4)a[k]=q[qf++];
		tmp[a[0]]=tmp[a[1]]=tmp[a[2]]=tmp[a[3]]=1;
		int res=query(tmp);
		tmp[a[0]]=tmp[a[1]]=tmp[a[2]]=tmp[a[3]]=0;
		if(res==0||res==4)ans[a[0]]=ans[a[1]]=ans[a[2]]=ans[a[3]]=res>>2;
		else if(res==1||res==3)
		{
			tmp[a[0]]=tmp[a[1]]=1;
			int res1=query(tmp);
			tmp[a[0]]=tmp[a[1]]=0;
			if(res1==1)
			{
				q[qr++]=a[0];
				fa[a[1]]=a[0];
				ans[a[2]]=ans[a[3]]=res>>1;
			}
			else
			{
				ans[a[0]]=ans[a[1]]=res>>1;
				q[qr++]=a[2];
				fa[a[3]]=a[2];
			}
		}
		else if(res==2)
		{
			tmp[a[0]]=tmp[a[1]]=1;
			int res1=query(tmp);
			tmp[a[0]]=tmp[a[1]]=0;
			if(res1==1)
			{
				q[qr++]=a[0];
				fa[a[1]]=a[0];
				q[qr++]=a[2];
				fa[a[3]]=a[2];
			}
			else
			{
				ans[a[0]]=ans[a[1]]=res1>>1;
				ans[a[2]]=ans[a[3]]=(res-res1)>>1;
			}
		}
	}
	F(i,qf,qr)tmp[q[i]]=1,ans[q[i]]=query(tmp),tmp[q[i]]=0;
	F(_,0,n)F(i,0,n)if(~fa[i])ans[i]=ans[fa[i]]^1;
	query(ans);
	return 0;
}