#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<queue>
using std::min;
using std::vector;
using std::unordered_map;
using std::queue;
int mod;
inline int add(int a,int b)
{
	if((a+=b)>=mod)
		a-=mod;
	return a;
}
inline int sub(int a,int b)
{
	if((a-=b)<0)
		a+=mod;
	return a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int p)
{
	int res=1;
	for(;p;a=mul(a,a),p>>=1)
		if(p&1)
			res=mul(res,a);
	return res;
}
struct cell
{
	int now,f;
};
int u,v;
vector<int> V;
unordered_map<int,int> pre,suc;
queue<cell> Q,Q2;
inline void print(int x)
{
	if(x==u)
		return;
	print(pre[x]);
	if(add(pre[x],1)==x)
		V.push_back(1);
	else if(sub(pre[x],1)==x)
		V.push_back(2);
	else
		V.push_back(3);
	return;
}
inline void print2(int x)
{
	if(x==v)
		return;
	if(add(x,1)==suc[x])
		V.push_back(1);
	else if(sub(x,1)==suc[x])
		V.push_back(2);
	else
		V.push_back(3);
	print2(suc[x]);
	return;
}
inline void out()
{
	register int i;
	printf("%d\n",(int)V.size());
	for(i=0;i<(int)V.size();i++)
		printf("%d ",V[i]);
	putchar('\n');
	exit(0);
	return;
}
signed main()
{
	int step,to;
	cell c;
	register int i;
	scanf("%d%d%d",&u,&v,&mod);
	pre[u]=0;suc[v]=0;
	Q.push(cell{u,0});Q2.push(cell{v,0});
	while(1)
		if(Q.size()<=Q2.size())
		{
			step=Q.front().f;
			while(Q.front().f==step)
			{
				c=Q.front();Q.pop();
				if(pre.find(to=add(c.now,1))==pre.end())
				{
					pre[to]=c.now;
					Q.push(cell{to,c.f+1});
					if(suc.find(to)!=suc.end())
					{
						print(to);print2(to);
						out();
					}
				}
				if(pre.find(to=sub(c.now,1))==pre.end())
				{
					pre[to]=c.now;
					Q.push(cell{to,c.f+1});
					if(suc.find(to)!=suc.end())
					{
						print(to);print2(to);
						out();
					}
				}
				if(pre.find(to=qpow(c.now,mod-2))==pre.end())
				{
					pre[to]=c.now;
					Q.push(cell{to,c.f+1});
					if(suc.find(to)!=suc.end())
					{
						print(to);print2(to);
						out();
					}
				}
			}
		}
		else
		{
			step=Q2.front().f;
			while(Q2.front().f==step)
			{
				c=Q2.front();Q2.pop();
				if(suc.find(to=add(c.now,1))==suc.end())
				{
					suc[to]=c.now;
					Q2.push(cell{to,c.f+1});
					if(pre.find(to)!=pre.end())
					{
						print(to);print2(to);
						out();
					}
				}
				if(suc.find(to=sub(c.now,1))==suc.end())
				{
					suc[to]=c.now;
					Q2.push(cell{to,c.f+1});
					if(pre.find(to)!=pre.end())
					{
						print(to);print2(to);
						out();
					}
				}
				if(suc.find(to=qpow(c.now,mod-2))==suc.end())
				{
					suc[to]=c.now;
					Q2.push(cell{to,c.f+1});
					if(pre.find(to)!=pre.end())
					{
						print(to);print2(to);
						out();
					}
				}
			}
		}
	return 0;
}