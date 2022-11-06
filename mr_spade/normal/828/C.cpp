%:pragma GCC optimize(2)
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using std::max;
using std::cin;
using std::cout;
using std::sort;
using std::string;
const int N=1e5+5,S=1e6+5;
int n,k,x,slen,len,cnt;
string s;
string t[N];
struct node
{
	int a;
	int b,e;
}c[S];
inline bool cmp(node x,node y)
{
	return x.b<y.b;
}
signed main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>t[i];
		len=t[i].size();
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&x);
			x--;
			c[++cnt].a=i;
			c[cnt].b=x;
			c[cnt].e=x+len-1;
			slen=max(slen,x+len);
		}
	}
	s.assign(slen,'a');
	sort(c+1,c+cnt+1,cmp);
	int prev=0;
	for(i=1;i<=cnt;i++)
	{
		if(c[i].e<prev)
			continue;
		for(j=max(c[i].b,prev);j<=c[i].e;j++)
			s[j]=t[c[i].a][j-c[i].b];
		prev=c[i].e+1;
		if(prev==slen)
			break;
	}
	cout<<s<<'\n';
	return 0;
}