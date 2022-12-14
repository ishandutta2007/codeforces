#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char s[444444],q[444444],ch;
int n,b[444444],ind[444444],sq,cur,ans,szz,sz,m,L,R,dp[444444],pos[444444];
int l[11111111],r[11111111],tree[11111111],rt[444444];
int upd(int lp,int rp,int x)
{
	int pos=++szz;
	tree[pos]=1;
	if (lp==rp) return pos;
	int mid=(lp+rp)/2;
	if (x>mid) r[pos]=upd(mid+1,rp,x);
	else l[pos]=upd(lp,mid,x);
	return pos; 
}
int merge(int x,int y)
{
	if (!x || !y) return x+y;
	int pos=++szz;
	tree[pos]=tree[x]+tree[y];
	l[pos]=merge(l[x],l[y]);
	r[pos]=merge(r[x],r[y]);
	return pos;
}
int query(int pos,int beg,int en,int lp,int rp)
{
	if (lp>en || rp<beg) return 0;
	if (lp>=beg && rp<=en) return tree[pos];
	int mid=(lp+rp)/2;
	return query(l[pos],beg,en,lp,mid)+query(r[pos],beg,en,mid+1,rp);
}
struct SAM
{
	int edge[444444][26],len[444444],fa[444444],cnt,last,pos[444444],rb[444444];
	void Init()
	{
		last=1;cnt=1;
		for (int i=0;i<n;i++)
		{
			int r=++cnt,p=last;
			len[r]=i+1;
			fa[r]=1;
			rb[r]=i+1;
			while(p>0 && !edge[p][s[i]-'a']) 
			{
				edge[p][s[i]-'a']=r;
				p=fa[p];
			}
			if (p)
			{
				int q=edge[p][s[i]-'a'];
				if (len[q]==len[p]+1) fa[r]=q;
				else
				{
					int qq=++cnt;
					for (int j=0;j<26;j++) edge[qq][j]=edge[q][j];
					len[qq]=len[p]+1;
					fa[qq]=fa[q];
					rb[qq]=rb[q];
					fa[q]=qq;
					fa[r]=qq;
					while(p && edge[p][s[i]-'a']==q) 
					{
						edge[p][s[i]-'a']=qq;
						p=fa[p];
					}
				}
			}
			last=r;
			pos[i]=last;
		}
	}
}sam;
int main()
{
    scanf("%d",&n);
	scanf("%s",s);
	sam.Init();
	for (int i=1;i<=sam.cnt;i++) b[sam.len[i]]++;
	for (int i=1;i<=n;i++) b[i]+=b[i-1];
	for (int i=sam.cnt;i>=1;i--) ind[b[sam.len[i]]--]=i;
	sz=1;
	while(sz<n) sz*=2;
	for (int i=0;i<n;i++) rt[sam.pos[i]]=upd(1,sz,i+1);
	for (int i=sam.cnt;i>1;i--)
	{
		rt[sam.fa[ind[i]]]=merge(rt[sam.fa[ind[i]]],rt[ind[i]]);
	}
	dp[ind[1]]=0;pos[ind[1]]=ind[1];
	for (int i=2;i<=sam.cnt;i++)
	{
	    int x=ind[i],f=sam.fa[x];
	    if (pos[f]==ind[1] || query(rt[pos[f]],sam.rb[x]-sam.len[x]+sam.len[sam.fa[pos[f]]]+1,sam.rb[x]-1,1,sz))
	    {
	        dp[x]=dp[pos[f]]+1;
	        pos[x]=x;
	    }
	    else
	    {
	        dp[x]=dp[pos[f]];
	        pos[x]=pos[f];
	    }
	    ans=max(ans,dp[x]);
	}
	printf("%d\n",ans);
	return 0;
}