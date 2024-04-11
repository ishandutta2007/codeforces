#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,l,r,cnt[27],ans[3*N],k;
char s[N],t[N],tmp[N];
void shift(int x)
{
	ans[k++]=x;
	F(i,0,n)tmp[i]=s[i];
	F(i,0,x)s[i]=tmp[n-1-i];
	F(i,x,n)s[i]=tmp[i-x];
}
void move(int x)
{
	shift(n-x-1);
	shift(1);
	shift(n-1);
}
int main()
{
	read(n);
	gets(s);gets(t);
	F(i,0,n)--cnt[s[i]-'a'];
	F(i,0,n)++cnt[t[i]-'a'];
	F(i,0,26)if(cnt[i])return puts("-1"),0;
	F(i,0,n)F(j,0,n)if(s[j]==t[i])move(j),j=n;
#ifdef ZKYAKIOI
	puts(s);
#endif
	printf("%d\n",k);
	F(i,0,k)printf("%d ",ans[i]);
	puts("");
	return 0;
}