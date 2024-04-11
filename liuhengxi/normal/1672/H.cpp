#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,q,s0[N],s1[N];
char s[N];
int main()
{
	read(n,q);
	scanf("%s",s);
	F(i,0,n)s0[i+1]=s0[i]+(s[i]=='0'&&s[i+1]=='0');
	F(i,0,n)s1[i+1]=s1[i]+(s[i]=='1'&&s[i+1]=='1');
	while(q--)
	{
		int l,r;--read(l),--read(r);
		printf("%d\n",max(s0[r]-s0[l],s1[r]-s1[l])+1);
	}
	return 0;
}