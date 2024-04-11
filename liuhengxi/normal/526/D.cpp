#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,nex[N];
char s[N],ans[N];
bool ok(int x)
{
	return (x+k)/(k+1)*k<x;
}
int main()
{
	read(n);read(k);gets(s);
	if(k==1)F(i,0,n)ans[i]='1';
	else
	{
		ans[0]='0';
		nex[0]=-1;nex[1]=0;
		for(int i=1,j=0;i<n;nex[i]=j)
		{
			while(j&&s[j]!=s[i])j=nex[j];
			if(s[j]==s[i])++j;
			++i;
			ans[i-1]=(i%(i-j)==0&&i/(i-j)%k==0)||ok((i-1)/(i-j)+1)?'1':'0';
		}
	}
	puts(ans);
	return 0;
}