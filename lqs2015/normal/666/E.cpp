#include<bits/stdc++.h>
using namespace std;
char s[555555];
int t[1111111],n,m,ct,cnt,ln,sa[1111111],lcp[1111111],k,rnk[1111111],buc[1111111],crt,arr[1111111],cur,tmp[1111111];
const int magic=347;
bool cmp(int i,int j)
{
	int ri=i+k<cnt ? rnk[i+k] : -1;
	int rj=j+k<cnt ? rnk[j+k] : -1;
	return (rnk[i]==rnk[j] && ri==rj);
}
void make_sa()
{
	for (int i=0;i<ct;i++) buc[i]=0;
	for (int i=0;i<cnt;i++) buc[t[i]]++;
	for (int i=1;i<ct;i++) buc[i]+=buc[i-1];
	for (int i=0;i<cnt;i++) sa[--buc[t[i]]]=i;
	for (int i=0;i<cnt;i++) rnk[i]=t[i];
	for (k=1;k<=cnt;k*=2)
	{
		cur=0;
		for (int i=cnt-k;i<cnt;i++) arr[cur++]=i;
		for (int i=0;i<cnt;i++)
		{
			if (sa[i]>=k) arr[cur++]=sa[i]-k;
		}
		for (int i=0;i<cnt;i++) buc[i]=0;
		for (int i=0;i<cnt;i++) buc[rnk[i]]++;
		for (int i=1;i<cnt;i++) buc[i]+=buc[i-1];
		for (int i=cnt-1;i>=0;i--) sa[--buc[rnk[arr[i]]]]=arr[i];
		tmp[sa[0]]=0;
		for (int i=1;i<cnt;i++) 
		{
			if (cmp(sa[i-1],sa[i])) tmp[sa[i]]=tmp[sa[i-1]];
			else tmp[sa[i]]=tmp[sa[i-1]]+1;
		}
		for (int i=0;i<cnt;i++) rnk[i]=tmp[i];
	}
}
void make_lcp()
{
	int h=0;
	for (int i=0;i<cnt;i++) rnk[sa[i]]=i;
	for (int i=0;i<cnt;i++)
	{
		if (!rnk[i]) continue;
		int j=sa[rnk[i]-1];
		if (h>0) h--;
		for (;i+h<cnt && j+h<cnt;h++)
		{
			if (t[i+h]!=t[j+h]) break;
		}
		lcp[rnk[i]-1]=h;
	}
}
int st[1111111][22],Log[1111111],sz,pos[1111111],q,cpt,a[111111],col[111111],l,r,pl,pr,len,L,R,curl,curr;
pair<int,int> tree[444444],ans[666666];
struct que
{
	int l,r,pl,pr,id;
}g[1111111];
int getmin(int a,int b)
{
	if (a>b) return 1e9;
	int x=Log[b-a+1];
	return min(st[a][x],st[b-(1<<x)+1][x]);
}
bool cmp1(que x,que y)
{
	if (x.l/magic!=y.l/magic) return x.l<y.l;
	return x.r<y.r; 
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=make_pair(0,-l);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
void update(int x,int del)
{
	int pos=sz-1+x;
	tree[pos].first+=del;
	pos>>=1;
	while(pos>=1)
	{
		tree[pos]=max(tree[pos<<1],tree[(pos<<1)|1]);
		pos>>=1;
	}
}
pair<int,int> query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return make_pair(-1e9,-1e9);
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		t[i]=s[i]-'a'+1;
	}
	cnt=n;ct=27;
	t[cnt++]=ct++;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);
		ln=strlen(s);
		for (int j=0;j<ln;j++) t[cnt++]=s[j]-'a'+1;
		if (i!=m) t[cnt++]=ct++;
	}
	make_sa();
	make_lcp();
	Log[1]=0;
	for (int i=2;i<=cnt;i++) Log[i]=Log[i/2]+1;
	for (int i=0;i<cnt-1;i++) 
	{
		st[i][0]=lcp[i];
	}
	for (int i=1;i<=20;i++)
	{
		for (int j=0;j<cnt-1;j++)
		{
			st[j][i]=st[j][i-1];
			if (j+(1<<i)<cnt-1) st[j][i]=min(st[j][i],st[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i=n;i<cnt;i++)
	{
		if (t[i]>26) crt++;
		else pos[i]=crt;
	}
	for (int i=0;i<cnt;i++) 
	{
		if (pos[sa[i]]) 
		{
			cpt++;
			a[cpt]=i;
			col[cpt]=pos[sa[i]];
		}
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		pl--;pr--;
		len=pr-pl+1;
		L=0;R=rnk[pl];
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if (getmin(mid,rnk[pl]-1)>=len) R=mid-1;
			else L=mid+1;
		}
		curl=L;L=rnk[pl];R=cnt-1;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if (getmin(rnk[pl],mid-1)>=len) L=mid+1;
			else R=mid-1;
		}
		curr=R;
		g[i].pl=l;g[i].pr=r;
		g[i].l=lower_bound(a+1,a+cpt+1,curl)-a;
		g[i].r=lower_bound(a+1,a+cpt+1,curr)-a;
		if (g[i].r>cpt || a[g[i].r]>curr) g[i].r--;
		g[i].id=i;
	}
	sort(g+1,g+q+1,cmp1);
	sz=1;
	while(sz<m) sz*=2;
	build(1,sz,1);
	L=1;R=0;
	for (int i=1;i<=q;i++)
	{
		while(L<g[i].l) update(col[L++],-1);
		while(L>g[i].l) update(col[--L],1);
		while(R<g[i].r) update(col[++R],1);
		while(R>g[i].r) update(col[R--],-1);
		pair<int,int> res=query(g[i].pl,g[i].pr,1,sz,1);
		ans[g[i].id]=make_pair(-res.second,res.first);
	}
	for (int i=1;i<=q;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}