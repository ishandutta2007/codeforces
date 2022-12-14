#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18;
char s[2222];
int n,m,cnt,l,r,mid,rp[2222];
long long k,suf[1111][1111],dp[1111][1111];
struct substring
{
	int l,r,node;
	bool operator == (const substring &u)
	{
		if (node!=u.node) return 0;
		return (r-l==u.r-u.l);
	}
}a[1111111];
long long Plus(long long a,long long b)
{
	if (a+b>inf) return inf;
	return a+b;
}
struct SAM
{
	int edge[5555][26],len[5555],fa[5555],buc[1000005],ord[1000005],cnt,last;
	vector<int> rig[5555];
	void extend(int i,char c)
	{
		int r=++cnt,p=last;
		len[r]=i+1;
		fa[r]=1;
		rig[r].push_back(i+1);
		while(p>0 && !edge[p][c-'a']) 
		{
			edge[p][c-'a']=r;
			p=fa[p];
		}
		if (p)
		{
			int q=edge[p][c-'a'];
			if (len[q]==len[p]+1) 
			{
				fa[r]=q;
			}
			else
			{
				int qq=++cnt;
				for (int j=0;j<26;j++) edge[qq][j]=edge[q][j];
				len[qq]=len[p]+1;
				fa[qq]=fa[q];
				fa[q]=qq;
				fa[r]=qq;
				while(p && edge[p][c-'a']==q) 
				{
					edge[p][c-'a']=qq;
					p=fa[p];
				}
			}
		}
		last=r;
	}
	void Init()
	{
		last=1;cnt=1;
	}
	void build()
	{
		for (int i=1;i<=cnt;i++) buc[len[i]]++;
		for (int i=1;i<=len[last];i++) buc[i]+=buc[i-1];
		for (int i=1;i<=cnt;i++) ord[buc[len[i]]--]=i;
		for (int i=cnt;i>=1;i--) 
		{
			for (int j=0;j<rig[ord[i]].size();j++)
			{
				rig[fa[ord[i]]].push_back(rig[ord[i]][j]);
			}
		}
	}
}sam;
void Sort(int i,int len)
{
	if (len)
	{
		for (int j=0;j<sam.rig[i].size();j++)
		{
			a[++cnt]=(substring){sam.rig[i][j]-len+1,sam.rig[i][j],i};
		}
	}
	for (int j=0;j<26;j++)
	{
		if (sam.edge[i][j]) Sort(sam.edge[i][j],len+1);
	}
}
bool check()
{
	for (int i=1;i<=n;i++) rp[i]=n+1;
	for (int i=cnt;i>=mid;i--)
	{
		rp[a[i].l]=a[i].r;
	}
	memset(dp,0,sizeof(dp));memset(suf,0,sizeof(suf));
	dp[n+1][0]=1;suf[n+1][0]=1;
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=m;j++)
		{
			dp[i][j]=suf[rp[i]+1][j-1];
		}
		for (int j=0;j<=m;j++)
		{
			suf[i][j]=Plus(suf[i+1][j],dp[i][j]);
		}
	}
	return (dp[1][m]<k);
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",s);
	sam.Init();
	for (int i=0;i<n;i++) sam.extend(i,s[i]);
	sam.build();
	Sort(1,0);
	l=1;r=cnt;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check()) r=mid-1;
		else l=mid+1;
	}
	for (int i=a[r].l;i<=a[r].r;i++)
	{
		putchar(s[i-1]);
	}
	putchar('\n');
	return 0;
}