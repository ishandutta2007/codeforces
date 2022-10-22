#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T>T read(){T x;readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,q,MOD,c[N],d[N],f[N],o;
int main()
{
	read(n,q,MOD);n+=2;
	F(i,2,n)c[i]+=read<int>();
	F(i,2,n)c[i]-=read<int>(),c[i]+=c[i]>>31&MOD;
	for(int i=n+2;--i>=2;)c[i]-=c[i-1],c[i]+=c[i]>>31&MOD,c[i]-=c[i-2],c[i]+=c[i]>>31&MOD;
	F(i,0,n+2)o+=!!c[i];
	f[0]=f[1]=MOD!=1;
	F(i,2,n)f[i]=f[i-1]+f[i-2],(f[i]>=MOD)&&(f[i]-=MOD);
	while(q--)
	{
		char op[2];int l,r;scanf("%s",op);read(l,r);++l,r+=2;
		o-=(!!c[l])+(!!c[r])+(!!c[r+1]);
		if(op[0]=='A')c[l]+=1-MOD,c[r]-=f[r-l],c[r+1]-=f[r-l-1];
		if(op[0]=='B')c[l]-=1,c[r]+=f[r-l]-MOD,c[r+1]+=f[r-l-1]-MOD;
		c[l]+=c[l]>>31&MOD;c[r]+=c[r]>>31&MOD;c[r+1]+=c[r+1]>>31&MOD;
		o+=(!!c[l])+(!!c[r])+(!!c[r+1]);
		puts(o?"NO":"YES");
	}
	return 0;
}