#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=(1<<8)+5;
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
struct event{int tm,id,tp;}e[N<<1];
bool operator<(event u,event v){return u.tm!=v.tm?u.tm<v.tm:u.tp>v.tp;}
int n,m_,k,s,f[M],bit[N];
int main()
{
	read(n,m_,k);s=(1<<k)-1;
	F(i,0,n)
	{
		int l,r;--read(l),read(r);
		e[i<<1].tm=l,e[i<<1|1].tm=r;
		e[i<<1].id=i,e[i<<1|1].id=i;
		e[i<<1].tp=0,e[i<<1|1].tp=1;
	}
	sort(e,e+(n<<1));
	F(i,0,n<<1)
	{
		int delta=i?e[i].tm-e[i-1].tm:0;
		F(j,0,1<<k)if((!(j&s))&&__builtin_parity(j))f[j]+=delta;
		if(e[i].tp)
		{
			s^=bit[e[i].id];
			F(j,0,1<<k)if(!(j&s))f[j]=max(f[j],f[j^bit[e[i].id]]);
		}
		else
		{
			bit[e[i].id]=s&-s;
			F(j,0,1<<k)if(!(j&s))f[j^bit[e[i].id]]=f[j];
			s^=bit[e[i].id];
		}
	}
	printf("%d\n",f[0]);
	return 0;
}