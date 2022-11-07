#include<cstdio>
#include<vector>
using std::swap;
using std::vector;
const int N=1e6+5;
int n,idx;
int bk[N];
int c[N],key[N][3],p[N],deg[N];
vector<int> V,W;
inline int top(int k)
{
	return V[(int)V.size()-k];
}
inline bool judge()
{
	if((int)V.size()<3)
		return 0;
	return bk[top(1)]==bk[top(2)]&&bk[top(2)]==bk[top(3)];
}
signed main()
{
	int x;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=3*n;i++)
		scanf("%d",&x),bk[x]=1;
	for(i=1;i<=6*n;i++)
	{
		V.push_back(i);
		if(judge())
		{
			c[++idx]=bk[top(1)];
			key[idx][2]=top(1);
			key[idx][1]=top(2);
			key[idx][0]=top(3);
			V.pop_back();
			V.pop_back();
			V.pop_back();
			while(!W.empty()&&key[W.back()][0]>key[idx][0])
				p[W.back()]=idx,deg[idx]++,W.pop_back();
			W.push_back(idx);
		}
	}
	W.clear();
	for(i=1;i<=idx;i++)
		if(!deg[i])
		{
			if(c[i]==1)
				V.push_back(i);
			else
				W.push_back(i);
		}
	for(i=1;i<=n;i++)
	{
		printf("%d %d %d\n",key[V.back()][0],key[V.back()][1],key[V.back()][2]);
		if(!--deg[p[V.back()]])
			W.push_back(p[V.back()]);
		V.pop_back();
		if(!p[W.back()]&&(int)W.size()>1)
			swap(W[(int)W.size()-1],W[(int)W.size()-2]);
		printf("%d %d %d\n",key[W.back()][0],key[W.back()][1],key[W.back()][2]);
		if(!--deg[p[W.back()]])
			V.push_back(p[W.back()]);
		W.pop_back();
	}
	return 0;
}