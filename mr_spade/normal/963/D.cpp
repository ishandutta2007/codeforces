#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::sort;
typedef unsigned long long ull;
const int base=31;
const int N=1e5+7;
int n;
int slen,tlen;
char s[N],t[N];
int sa[N],rank[N<<1];
int x[N],y[N],cnt[N];
ull h[N],ht[N],powb[N];
inline ull hash(int l,int r)
{
	return h[r]-powb[r-l+1]*h[l-1];
}
inline ull hasht(int l,int r)
{
	return ht[r]-powb[r-l+1]*ht[l-1];
}
inline void get_sa(int n)
{
	int m=26,p;
	register int i,k;
	memset(rank+1,0,sizeof(int)*(n<<1));
	for(i=1;i<=n;i++)
		rank[i]=s[i]-'a'+1,x[i]=i;
	for(k=1;k<n;k<<=1)
	{
		memset(cnt,0,sizeof(int)*(m+1));
		for(i=1;i<=n;i++)
			++cnt[rank[x[i]+k]];
		for(i=1;i<=m;i++)
			cnt[i]+=cnt[i-1];
		for(i=n;i>=1;i--)
			y[cnt[rank[x[i]+k]]--]=x[i];
		memset(cnt,0,sizeof(int)*(m+1));
		for(i=1;i<=n;i++)
			++cnt[rank[y[i]]];
		for(i=1;i<=m;i++)
			cnt[i]+=cnt[i-1];
		for(i=n;i>=1;i--)
			x[cnt[rank[y[i]]]--]=y[i];
		memset(cnt,0,sizeof(int)*(m+1));
		for(cnt[x[1]]=p=1,i=2;i<=n;i++)
			cnt[x[i]]=(rank[x[i]]==rank[x[i-1]]&&rank[x[i]+k]==rank[x[i-1]+k]?p:++p);
		memmove(rank+1,cnt+1,sizeof(int)*n);
		if(p>=n)
		{
			memmove(sa+1,x+1,sizeof(int)*n);
			break;
		}
		m=p+1;
	}
	return;
}
inline int cmp(int y)
{
	int l=0,r=min(tlen,slen-y+1),mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(hasht(1,mid)==hash(y,y+mid-1))
			l=mid;
		else
			r=mid-1;
	}
	if(l==tlen)
		return 0;
	if(l==slen-y+1)
		return -1;
	return s[y+l]<t[l+1]?-1:1;
}
signed main()
{
	int L,R,k,l,r,mid,res;
	register int i;
	scanf("%s",s+1);
	slen=strlen(s+1);
	powb[0]=1;
	for(i=1;i<=slen;i++)
		h[i]=h[i-1]*base+s[i]-'a'+1,powb[i]=powb[i-1]*base;
	get_sa(slen);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%s",&k,t+1);
		tlen=strlen(t+1);
		for(i=1;i<=tlen;i++)
			ht[i]=ht[i-1]*base+t[i]-'a'+1;
		l=1;r=slen+1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(cmp(sa[mid])<=0)
				l=mid+1;
			else
				r=mid;
		}
		R=l;
		l=1;r=slen+1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(cmp(sa[mid])<0)
				l=mid+1;
			else
				r=mid;
		}
		L=l;
		if(R-L<k)
		{
			puts("-1");
			continue;
		}
		for(i=L;i<R;i++)
			x[i]=sa[i];
		sort(x+L,x+R);
		res=0x3f3f3f3f;
		for(i=L;i+k-1<R;i++)
			if(x[i+k-1]-x[i]<res)
				res=x[i+k-1]-x[i];
		printf("%d\n",res+tlen);
	}
	return 0;
}