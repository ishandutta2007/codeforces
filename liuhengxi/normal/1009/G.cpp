#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,allow[N],c[10],r[70],t[70],m;
char s[N],tmp[10],ans[N];
bool ok()
{
	F(i,1,64)
	{
		r[i]=r[i^(i&-i)]+c[__builtin_ctz(i)];
		if(r[i]>t[i])return false;
	}
	return true;
}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	F(i,0,n)++c[s[i]-'a'];
	F(i,0,n)allow[i]=63;
	read(m);
	F(i,0,m)
	{
		int pos;--read(pos);
		scanf("%s",tmp);
		allow[pos]=0;
		for(int j=0;tmp[j];++j)allow[pos]|=1<<(tmp[j]-'a');
	}
	F(i,0,n)F(j,0,64)if(allow[i]&j)++t[j];
	if(!ok())return puts("Impossible"),0;
	F(i,0,n)
	{
		F(j,0,64)if(allow[i]&j)--t[j];
		F(k,0,6)if(c[k]&&(allow[i]>>k&1))
		{
			--c[k];
			ans[i]='a'+k;
			if(ok())break;
			++c[k];
		}
	}
	puts(ans);
	return 0;
}