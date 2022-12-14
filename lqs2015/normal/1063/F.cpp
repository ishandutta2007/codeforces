#include<bits/stdc++.h>
using namespace std;
char s[555555];
int tree[22222222],sz,L,R,mid,ans;
int t[1111111],sa[1111111],lcp[1111111],buc[1111111],arr[1111111],k,rnk[1111111],n,cur,tmp[1111111],dp[1111111],st[555555][22],Log[555555];
const int ct=27;
bool cmp(int i,int j)
{
	int ri=i+k<n ? rnk[i+k] : -1;
	int rj=j+k<n ? rnk[j+k] : -1;
	return (rnk[i]==rnk[j] && ri==rj);
}
void make_sa()
{
	for (int i=0;i<ct;i++) buc[i]=0;
	for (int i=0;i<n;i++) buc[t[i]]++;
	for (int i=1;i<ct;i++) buc[i]+=buc[i-1];
	for (int i=0;i<n;i++) sa[--buc[t[i]]]=i;
	for (int i=0;i<n;i++) rnk[i]=t[i];
	for (k=1;k<=n;k*=2)
	{
		cur=0;
		for (int i=n-k;i<n;i++) arr[cur++]=i;
		for (int i=0;i<n;i++)
		{
			if (sa[i]>=k) arr[cur++]=sa[i]-k;
		}
		for (int i=0;i<n;i++) buc[i]=0;
		for (int i=0;i<n;i++) buc[rnk[i]]++;
		for (int i=1;i<n;i++) buc[i]+=buc[i-1];
		for (int i=n-1;i>=0;i--) sa[--buc[rnk[arr[i]]]]=arr[i];
		tmp[sa[0]]=0;
		for (int i=1;i<n;i++) 
		{
			if (cmp(sa[i-1],sa[i])) tmp[sa[i]]=tmp[sa[i-1]];
			else tmp[sa[i]]=tmp[sa[i-1]]+1;
		}
		for (int i=0;i<n;i++) rnk[i]=tmp[i];
	}
}
void make_lcp()
{
	int h=0;
	for (int i=0;i<n;i++) rnk[sa[i]]=i;
	for (int i=0;i<n;i++)
	{
        if (!rnk[i]) continue;
		int j=sa[rnk[i]-1];
		if (h>0) h--;
		for (;i+h<n && j+h<n;h++)
		{
			if (t[i+h]!=t[j+h]) break;
		}
		lcp[rnk[i]-1]=h;
	}
}
int get(int l,int r)
{
	int x=Log[r-l+1];
	return min(st[l][x],st[r-(1<<x)+1][x]);
}
int query(int beg,int en,int lp,int rp,int node)
{
	if (lp>en || rp<beg) return 0;
	if (lp>=beg && rp<=en) return tree[node];
	int mid=(lp+rp)>>1;
	return max(query(beg,en,lp,mid,node<<1),query(beg,en,mid+1,rp,(node<<1)|1));
}
bool chk(int x,int len)
{
	int l,r,mid,L,R;
	l=0;r=rnk[x]-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (get(mid,rnk[x]-1)>=len) r=mid-1;
		else l=mid+1;
	}
	L=l;l=rnk[x]+1;r=n-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (get(rnk[x],mid-1)>=len) l=mid+1;
		else r=mid-1;
	}
	R=r;L++;R++;
	if (query(L,R,1,n,1)>=len) return 1;
	return 0;
}
bool check(int x,int len)
{
	if (!len) return 1;
	return (chk(x,len) || chk(x+1,len));
}
void update(int x,int lp,int rp,int node,int y)
{
	tree[node]=max(tree[node],y);
	if (lp==rp) return;
	int mid=(lp+rp)>>1;
	if (x>mid) update(x,mid+1,rp,(node<<1)|1,y);
	else update(x,lp,mid,node<<1,y);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++) t[i]=s[i]-'a'+1;
	make_sa();
	make_lcp();
	Log[1]=0;
	for (int i=2;i<=n;i++) Log[i]=Log[i>>1]+1;
	for (int i=0;i<n-1;i++) st[i][0]=lcp[i];
	for (int i=1;i<=19;i++)
	{
		for (int j=0;j<n-1;j++)
		{
			st[j][i]=st[j][i-1];
			if (j+(1<<(i-1))<n-1) st[j][i]=min(st[j][i],st[j+(1<<(i-1))][i-1]);
		}
	}
	dp[n-1]=1;
	for (int i=n-2;i>=0;i--)
	{
		for (int j=dp[i+1]+1;j>=1;j--)
		{
			if (check(i,j-1))
			{
				dp[i]=j;
				break;
			}
			update(rnk[i+j-1]+1,1,n,1,dp[i+j-1]);
		}
	}
	for (int i=0;i<n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}