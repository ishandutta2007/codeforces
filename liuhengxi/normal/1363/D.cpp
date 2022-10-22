#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,k,m[N],s[N][N],ans[N];
bool b[N];
char res[N];
int query(int l,int r)
{
	int tot=0;
	F(i,l,r)tot+=m[i];
	printf("? %d ",tot);
	F(i,l,r)F(j,0,m[i])printf("%d ",s[i][j]+1);
	printf("\n");
	fflush(stdout);
	read(tot);
	return tot;
}
int query2(int x)
{
	int tot;
	printf("? %d ",n-m[x]);
	F(i,0,n)b[i]=true;
	F(i,0,m[x])b[s[x][i]]=false;
	F(i,0,n)if(b[i])printf("%d ",i+1);
	printf("\n");
	fflush(stdout);
	read(tot);
	return tot;
}
int main()
{
	read(t);
	while(t--)
	{
		int l=0,r=0,allmax;
		read(n);read(k);r=k;
		F(i,0,k)
		{
			read(m[i]);
			F(j,0,m[i])read(s[i][j]),--s[i][j];
		}
		printf("? %d ",n);
		F(i,0,n)printf("%d ",i+1);
		printf("\n");
		fflush(stdout);
		read(allmax);
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(query(l,mid)==allmax)r=mid;
			else l=mid;
		}
		F(i,0,k)if(i!=l)ans[i]=allmax;
		ans[l]=query2(l);
		printf("! ");
		F(i,0,k)printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
		gets(res);
		if(res[0]=='I')return 0;
	}
	return 0;
}