#include<bits/stdc++.h>
using namespace std;
int n,x,y,dep[555555],DEP[555555],prem[555555],sufm[555555],iden,arr[555555],pa[555555],cnt,cur,tree[2222222];
int ans1[555555],ans2[555555],pre[555555],nxt[555555];//2*k,2*k+1
vector<int> g[555555],v;
int brr[555555],bcnt;
void dfs(int i,int fa)
{
	pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		dep[i]=max(dep[i],dep[to]+1);
	}
	int cr=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		pre[to]=cr;nxt[cr]=to;
		cr=to;
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		prem[to]=max(prem[pre[to]],dep[to]+1);
	}
	for (int j=(int)g[i].size()-1;j>=0;j--)
	{
		int to=g[i][j];
		if (to==fa) continue;
		sufm[to]=max(sufm[nxt[to]],dep[to]+1);
	}
}
void dft(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		DEP[to]=1+max(DEP[i],max(prem[pre[to]],sufm[nxt[to]]));
		dft(to,i);
	}
}
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]=max(tree[node],x);
		v.push_back(node);
		return;
	}
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
}
int qry(int x,int l,int r,int node)
{
	if (l==r)
	{
		return tree[node];
	}
	int mid=(l+r)>>1;
	if (x>mid) return max(qry(x,mid+1,r,(node<<1)|1),tree[node]);
	return max(qry(x,l,mid,node<<1),tree[node]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	dft(1,0);
	for (int i=1;i<=n;i++) iden=max(iden,(int)g[i].size()+1);
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to!=pa[i]) arr[++cnt]=dep[to]+1;
		}
		if (i!=1) arr[++cnt]=DEP[i];
		sort(arr+1,arr+cnt+1,greater<int>());
		for (int j=1;j<=cnt;j++)
		{
			cur=j+(j!=cnt && arr[j+1]==arr[j]-1);
			ans2[arr[j]-1]=max(ans2[arr[j]-1],cur);
		}
		for (int j=2;j<=cnt;j++)
		{
			if (arr[j]==arr[j-1]) continue;
			ans2[arr[j]]=max(ans2[arr[j]],j);
		}
		for (int j=2;j<=cnt;j++)
		{
			ans1[arr[j]]=max(ans1[arr[j]],j);
		}
	}
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to!=pa[i]) arr[++cnt]=dep[to]+1;
		}
		if (i!=1) arr[++cnt]=DEP[i];
		sort(arr+1,arr+cnt+1);
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to==pa[i]) continue;
			bcnt=0;
			for (int k=0;k<g[to].size();k++)
			{
				int tt=g[to][k];
				if (tt!=pa[to]) brr[++bcnt]=dep[tt]+1;
			}
			if (to!=1) brr[++bcnt]=DEP[to];
			sort(brr+1,brr+bcnt+1,greater<int>());
			for (int k=1;k<=bcnt;k++)
			{
				int xx=lower_bound(arr+1,arr+cnt+1,brr[k])-arr;
				ans1[brr[k]]=max(ans1[brr[k]],k+(cnt-xx+1)-2); 
			}
			for (int k=1;k<=bcnt;k++)
			{
				update(1,brr[k],1,n,1,k);
			}
		}
		for (int j=1;j<=cnt;j++)
		{
			ans1[arr[j]]=max(ans1[arr[j]],cnt-j+1+qry(arr[j],1,n,1)-2);
		}
		for (int j=0;j<v.size();j++) tree[v[j]]=0;
		v.clear();
	}
	for (int i=n;i>=1;i--)
	{
		ans1[i]=max(1,max(ans1[i],ans1[i+1]));
		ans2[i]=max(1,max(ans2[i],ans2[i+1]));
	}
	for (int i=1;i<=n;i++)
	{
		if (i==1) printf("%d ",iden);
		else if (i%2==0) printf("%d ",ans1[i/2]);
		else printf("%d ",ans2[i/2]);
	}
	printf("\n");
	return 0;
}