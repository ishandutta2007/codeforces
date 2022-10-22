#include<cstdio>
#include<vector>
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
constexpr int N=2e5+5;
int pool[N],*cur=pool;
int n,c[N],*cyc[N],len[N],cc,ox[N],oy[N],q;
void operate(int x,int y)
{
	ox[q]=x;oy[q]=y;++q;
}
bool vis[N];
int main()
{
	read(n);
	F(i,0,n)--read(c[i]);
	F(i,0,n)if(!vis[i])
	{
		cyc[cc]=cur;
		for(int j=i;~j;j=c[j],j==i&&(j=-1))
		{
			vis[j]=true;
			cyc[cc][len[cc]++]=j;
		}
		cur+=len[cc++];
	}
	while(cc>1)
	{
		cc-=2;
		operate(cyc[cc][0],cyc[cc+1][0]);
		F(i,1,len[cc])operate(cyc[cc][i],cyc[cc+1][0]);
		F(i,1,len[cc+1])operate(cyc[cc][0],cyc[cc+1][i]);
		operate(cyc[cc][0],cyc[cc+1][0]);
	}
	if(cc==1&&len[0]>1)
	{
		if(len[0]>2)
		{
			operate(cyc[0][len[0]-1],cyc[0][len[0]-2]);
			F(i,0,len[0]-2)operate(cyc[0][len[0]-1],cyc[0][i]);
			operate(cyc[0][0],cyc[0][len[0]-2]);
			operate(cyc[0][len[0]-1],cyc[0][len[0]-2]);
		}
		else
		{
			operate(cyc[1][0],cyc[0][0]);
			operate(cyc[1][0],cyc[0][1]);
			operate(cyc[1][0],cyc[0][0]);
		}
	}
	printf("%d\n",q);
	F(i,0,q)printf("%d %d\n",ox[i]+1,oy[i]+1);
	return 0;
}