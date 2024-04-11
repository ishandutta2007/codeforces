#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=(1<<24)+5,k=24,m=1<<k;
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
int n,c[M],a;
char s[4];
int main()
{
	read(n);
	F(i,0,n)
	{
		scanf("%s",s);
		int x=(s[0]-97<24)<<(s[0]-97);
		int y=(s[1]-97<24)<<(s[1]-97);
		int z=(s[2]-97<24)<<(s[2]-97);
		++c[x],++c[y],++c[z],--c[x|y],--c[y|z],--c[z|x],++c[x|y|z];
	}
	for(int i=1;i<m;i<<=1)for(int j=0;j<m;++j,j+=j&i)c[j|i]+=c[j];
	F(i,0,m)a^=c[i]*c[i];
	printf("%d\n",a);
	return 0;
}