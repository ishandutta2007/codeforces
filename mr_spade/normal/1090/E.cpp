#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#define mp make_pair
#define fi first
#define se second
using std::pair;
using std::mp;
using std::vector;
using std::queue;
const int dx[]={-1,1,-2,2,-2,2,-1,1},dy[]={-2,-2,-1,-1,1,1,2,2};
const int d[]={-17,-15,-10,-6,6,10,15,17};
int n;
char s[100];
int can[640][8];
int ch[640];
int inq[640],pre[640];
queue<int> Q;
vector<pair<int,int> > V;
int lg[1<<21];
int op,ed,st[1<<21],p[1<<21];
inline void print(int x)
{
	putchar(x%8+'a');
	putchar(x/8+'1');
	return;
}
inline void out(int x)
{
	if(x==op)
		return;
	int a,b;
	out(p[x]);
	b=lg[x^(x&p[x])];
	a=lg[p[x]^(x&p[x])];
	V.push_back(mp(44+a,44+b));
	return;
}
inline void do_sth()
{
	out(ed);
	return;
}
signed main()
{
//	freopen("test.in","r",stdin);
	int x;
	register int i,j,k;
	for(i=0;i<20;i++)
		lg[1<<i]=i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		ch[(s[1]-'1')*8+(s[0]-'a')]=1;
	}
	for(i=0;i<64;i++)
	{
		for(j=0;j<8;j++)
			if((i%8)+dx[j]>=0&&(i%8)+dx[j]<8&&(i/8)+dy[j]>=0&&(i/8)+dy[j]<8)
				can[i][j]=1;
	}
	for(i=0;i<n&&i<44;i++)
	{
		Q.push(i);inq[i]=1;pre[i]=-1;
		while(!Q.empty())
		{
			x=Q.front();Q.pop();
			if(ch[x])
				break;
			for(j=0;j<8;j++)
				if(x+d[j]>=i&&can[x][j]&&!inq[x+d[j]])
					Q.push(x+d[j]),inq[x+d[j]]=1,pre[x+d[j]]=x;
		}
		ch[x]=0;ch[i]=1;
		for(j=x;~pre[j];j=pre[j])
			V.push_back(mp(j,pre[j]));
		while(!Q.empty())
			inq[Q.front()]=0,Q.pop();
		for(j=0;j<64;j++)
			inq[j]=pre[j]=0;
	}
	if(n<=44)
	{
		printf("%d\n",(int)V.size());
		for(i=0;i<(int)V.size();i++)
			print(V[i].fi),putchar('-'),print(V[i].se),putchar('\n');
		return 0;
	}
	for(i=44;i<64;i++)
		if(ch[i])
			op|=1<<(i-44);
	for(i=44;i<n;i++)
		ed|=1<<(i-44);
	p[op]=-1;Q.push(op);
	while(!Q.empty())
	{
		x=Q.front();Q.pop();
		if(x==ed)
		{
			do_sth();
			break;
		}
		for(j=44;j<64;j++)
			if(x>>(j-44)&1)
				for(k=0;k<8;k++)
					if(can[j][k]&&j+d[k]>=44&&j+d[k]<64&&!(x>>(j+d[k]-44)&1)&&p[x^(1<<(j-44))^(1<<(j+d[k]-44))]==0)
					{
						p[x^(1<<(j-44))^(1<<(j+d[k]-44))]=x;
						Q.push(x^(1<<(j-44))^(1<<(j+d[k]-44)));
					}
	}
	printf("%d\n",(int)V.size());
	for(i=0;i<(int)V.size();i++)
		print(V[i].fi),putchar('-'),print(V[i].se),putchar('\n');
	return 0;
}