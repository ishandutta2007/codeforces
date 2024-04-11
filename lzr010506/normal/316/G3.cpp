#include <bits/stdc++.h>
#define N 510000
using namespace std;
typedef long long ll;
char str[N],p[N];
int L[N],R[N];
queue<int> q;
namespace SAM
{
	int son[N << 1][26], pre[N << 1], len[N << 1];
	int in[N << 1], size[N << 1][11];
	int tot,last;
	void init()
	{
		tot = last = 1;
	}
	void Insert(int x, int i)
	{
		if(son[last][x])
		{
			int p = son[last][x];
			if(len[p] == len[last] + 1) last = p;
			else
			{
				int np = ++ tot;
				len[np] = len[last] + 1;
				pre[np] = pre[p];
				memcpy(son[np], son[p], sizeof(int) * 26);
				pre[p] = np;
				for(int q = last; son[q][x] == p; q = pre[q])
					son[q][x] = np;
				last = np;
			}
		}
		else
		{
			int p,np = ++ tot;
			len[np] = len[last]+1;
			for(p = last; p && !son[p][x]; p  =pre[p])
				son[p][x] = np;
			if(!p) pre[np] = 1;
			else
			{
				int q = son[p][x];
				if(len[q] == len[p] + 1)
					pre[np] = q;
				else
				{
					int nq = ++ tot;
					len[nq] = len[p] + 1;
					memcpy(son[nq], son[q], sizeof(int) * 26);
					pre[nq] = pre[q];
					pre[q] = pre[np] = nq;
					for(; son[p][x] == q; p = pre[p])
						son[p][x] = nq;
				}
			}
			last = np;
		}
		size[last][i] ++;
	}
	bool judge(int x, int m)
	{
		for(int i = 1; i <= m; i ++)
			if(size[x][i] < L[i] || size[x][i] > R[i])	return 0;
		return size[x][0]!=0;
	}
	ll slove(int m)
	{
		int i,x;
		ll ret;
		for(i = 1; i <= tot; i ++)
			in[pre[i]] ++;
		for(i = 1; i <= tot; i ++)
			if(!in[i])
				q.push(i);
		while(!q.empty())
		{
			x = q.front();
			q.pop();
			for(i = 0; i <= m; i ++)
				size[pre[x]][i] += size[x][i];
			in[pre[x]] --;
			if(!in[pre[x]]) q.push(pre[x]);
		}
		for(i = 1, ret = 0; i <= tot; i ++)
			if(judge(i, m))
				ret += len[i] - len[pre[i]];
		return ret;
	}
}
int main()
{
	int n,m,i,j;
	scanf("%s%d",str,&m);
	n=strlen(str);
	SAM::init();
	for(i = 0; i < n; i ++)
		SAM::Insert(str[i] - 'a', 0);
	for(i = 1; i <= m; i ++)
	{
		scanf("%s%d%d", p, L + i, R + i);
		n = strlen(p);
		SAM::last = 1;
		for(j = 0; j < n; j ++)
			SAM::Insert(p[j] - 'a', i);
	}
	printf("%d\n",SAM::slove(m));
	return 0;
}