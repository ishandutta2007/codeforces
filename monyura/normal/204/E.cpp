#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

const int SZ=200100;
int p[SZ],pn[SZ],c[SZ],cn[SZ],cnt[SZ];
int *rev=pn,*lcp=cn;

void init(char *str,int n)
{
	memset(cnt,0,sizeof(int)*300);
	rep(i,0,n)
		++cnt[str[i]];
	rep(i,1,300)
		cnt[i]+=cnt[i-1];
	rep(i,0,n)
		p[--cnt[str[i]]]=i;
	c[p[0]]=0;
	rep(i,1,n)
		if (str[p[i]]!=str[p[i-1]])
			c[p[i]]=c[p[i-1]]+1;
		else
			c[p[i]]=c[p[i-1]];
}

void buildSuf(char *str,int n)
{
	init(str,n);
	for (int h=1;h<n;h<<=1)
	{
		memset(cnt,0,sizeof(int)*n);
		rep(i,0,n)
		{
			if (p[i]-h<0) pn[i]=p[i]-h+n;
			else pn[i]=p[i]-h;
			++cnt[c[i]];
		}
		if (cnt[n-1]) return;
		rep(i,1,n)
			cnt[i]+=cnt[i-1];
		for (int i=n-1;i>=0;i--)
			p[--cnt[c[pn[i]]]]=pn[i];
		cn[p[0]]=0;
		rep(i,1,n)
			if (c[p[i]]==c[p[i-1]])
			{
				int a=p[i]+h;
				int b=p[i-1]+h;
				if (a>=n) a-=n;
				if (b>=n) b-=n;
				if (c[a]==c[b])
					cn[p[i]]=cn[p[i-1]];
				else
					cn[p[i]]=cn[p[i-1]]+1;
			}
			else
				cn[p[i]]=cn[p[i-1]]+1;
		memcpy(c,cn,sizeof(int)*n);
	}
}

void Kasai(char *str,int n)
{
	rep(i,0,n)
		rev[p[i]]=i;
	int len=0;
	rep(i,0,n)
	{
		if (rev[i]==n-1) continue;
		while (str[i+len]==str[p[rev[i]+1]+len]) ++len;
		lcp[rev[i]]=len;
		if (len>0) --len;
	}
}

int MX[800200]={0};
int lcpD[800200]={0};

void buildLCP(int v,int l,int r)
{
	if (l==r)
	{
		lcpD[v]=lcp[l];
		return;
	}
	int c=(l+r)>>1;
	buildLCP(2*v,l,c);
	buildLCP(2*v+1,c+1,r);
	lcpD[v]=min(lcpD[2*v],lcpD[2*v+1]);
}

void setMax(int v,int l,int r,int p,int val)
{
	if (l==r)
	{
		if (val>MX[v])
			MX[v]=val;
		return;
	}
	int c=(l+r)>>1;
	if (p<=c)
		setMax(2*v,l,c,p,val);
	else
		setMax(2*v+1,c+1,r,p,val);
	MX[v]=max(MX[2*v],MX[2*v+1]);
}

int getMax(int v,int l,int r,int lq,int rq)
{
	if (l==lq && r==rq)
		return MX[v];
	int c=(l+r)>>1;
	if (rq<=c)
		return getMax(2*v,l,c,lq,rq);
	else if (lq>c)
		return getMax(2*v+1,c+1,r,lq,rq);
	else
		return max(getMax(2*v,l,c,lq,c),getMax(2*v+1,c+1,r,c+1,rq));
}

int getMin(int v,int l,int r,int lq,int rq)
{
	if (l==lq && r==rq)
		return lcpD[v];
	int c=(l+r)>>1;
	if (rq<=c)
		return getMin(2*v,l,c,lq,rq);
	else if (lq>c)
		return getMin(2*v+1,c+1,r,lq,rq);
	else
		return min(getMin(2*v,l,c,lq,c),getMin(2*v+1,c+1,r,c+1,rq));
}

int Who[200100];
int Ind[200100];
int Len[100100];
ll Ans[100100]={0};
int Val[200100]={0};

int L[200100];

void calc(char *str, int n,int m,int k)
{
	buildSuf(str,n);
	Kasai(str,n);
	buildLCP(1,0,n-2);
	memset(L,-1,sizeof(L));
	int curr=0;
	int r=0;
	rep(i,0,n)
	{
		while (r<n && Who[p[r]]!=m && curr<k)
		{
			if (L[Who[p[r]]]<i)
				++curr;
			L[Who[p[r]]]=r;
			++r;
		}
		if (curr<k)
		{
			while (i<r)
			{
				int add=getMax(1,0,n-1,i,r-1);
				add=min(add,Len[Who[p[i]]]-Ind[p[i]]);
				Val[p[i]]=add;
				++i;
			}
			break;
		}
		int val=getMin(1,0,n-2,i,r-2);
		setMax(1,0,n-1,r-1,val);
		int add=getMax(1,0,n-1,i,r-1);
		add=min(add,Len[Who[p[i]]]-Ind[p[i]]);
		Val[p[i]]=add;
		if (L[Who[p[i]]]==i)
			--curr;
	}
	memset(MX,0,sizeof(MX));
	curr=0;
	rep(i,0,n)
		L[i]=n+1;
	for (int i=n-1;i>=0;i--)
	{
		if (Who[p[i]]==m)
		{
			r=i-1;
			continue;
		}
		while (r>=0 && curr<k)
		{
			if (L[Who[p[r]]]>i)
				++curr;
			L[Who[p[r]]]=r;
			--r;
		}
		if (curr<k)
		{
			while (i>=0)
			{
				int val=getMax(1,0,n-1,0,i);
				int add=getMax(1,0,n-1,r+1,i);
				add=min(add,Len[Who[p[i]]]-Ind[p[i]]);
				if (Val[p[i]]<add)
					Val[p[i]]=add;	
				Ans[Who[p[i]]]+=Val[p[i]];
				--i;
			}
			break;
		}
		int val=getMin(1,0,n-2,r+1,i-1);
		setMax(1,0,n-1,r+1,val);
		int add=getMax(1,0,n-1,r+1,i);
		add=min(add,Len[Who[p[i]]]-Ind[p[i]]);
		if (Val[p[i]]<add)
			Val[p[i]]=add;
		Ans[Who[p[i]]]+=Val[p[i]];
		if (L[Who[p[i]]]==i)
			--curr;
	}
}

void run()
{
	int n,k;
	cin>>n>>k;
	char str[200100]={0};
	char *curr=str;
	int pos=0;
	rep(i,0,n)
	{
		scanf(" %s",curr);
		int len=strlen(curr);
		Len[i]=len;
		rep(j,0,len)
		{
			Who[pos]=i;
			Ind[pos]=j;
			pos++;
		}
		Who[pos]=n;
		Ind[pos]=n;
		pos++;
		curr[len]='z'+1;
		curr+=len+1;
	}
	curr[-1]='z'+1;
	if (k==1)
	{
		rep(i,0,n)
			Ans[i]=ll(Len[i])*(Len[i]+1)/2;
	}
	else
		calc(str,pos,n,k);
	rep(i,0,n)
		printf("%lld ",Ans[i]);
	putchar('\n');
	
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*
3 2
lasdbqwrisdiasdfnasdfgcfsjdagee
lasdbqwrisdiasdfnasdfgcfsjdagee
zaazzzzzzzzaaaazzzzzzzzzzddzzzz


*/