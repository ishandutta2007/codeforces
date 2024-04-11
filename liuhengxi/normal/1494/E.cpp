#include<cstdio>
#include<unordered_map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=202183;
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
int n,m,mt,mts;
unordered_map<long long,int> s;
long long edge(int a,int b){return (long long)a*M+b;}
int main()
{
	read(n,m);
	while(m--)
	{
		char opt[3];
		scanf("%s",opt);
		if(opt[0]=='+')
		{
			int u,v;char c[3];--read(u),--read(v);scanf("%s",c);
			s[edge(u,v)]=c[0];
			if(s.count(edge(v,u)))
			{
				++mt;
				if(s[edge(v,u)]==c[0])++mts;
			}
		}
		if(opt[0]=='-')
		{
			int u,v;char c[3];--read(u),--read(v);c[0]=char(s[edge(u,v)]);
			s.erase(edge(u,v));
			if(s.count(edge(v,u)))
			{
				--mt;
				if(s[edge(v,u)]==c[0])--mts;
			}
		}
		if(opt[0]=='?')
		{
			int k;read(k);
			puts((k&1?mt:mts)?"YES":"NO");
		}
	}
	return 0;
}