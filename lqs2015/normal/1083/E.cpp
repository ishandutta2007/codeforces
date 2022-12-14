#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-9;
long long n,x,y,w;
pair<pair<long double,long double>,long double> a[1111111];
long double dp[1111111],ans;
pair<long double,long double> add,xx,yy;
deque<pair<long double,long double> > q;
long double g(pair<long double,long double> x,pair<long double,long double> y)
{
	return (x.second-y.second)/(y.first-x.first);
}
const long long maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
long long read()
{
    char c;
    long long re=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1ll)+(re<<3ll)+(c-'0'),c=Get_Char();
    return re;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		x=read();y=read();w=read();
		a[i]=make_pair(make_pair((long double)x,(long double)y),(long double)w);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		add=make_pair(-a[i-1].first.first,dp[i-1]);
		while(q.size()>1)
	 	{
	 		xx=q[q.size()-1];yy=q[q.size()-2];
	 		if (g(xx,add)>g(yy,xx)+eps) q.pop_back();
	 		else break;
		}
		q.push_back(add); 
		while(q.size()>1)
		{
			xx=q[0];yy=q[1];
			if (a[i].first.second*xx.first+xx.second<a[i].first.second*yy.first+yy.second) q.pop_front(); 
			else break;
		}
		xx=q[0];
		dp[i]=a[i].first.second*xx.first+xx.second+a[i].first.first*a[i].first.second-a[i].second;
	}
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	printf("%.0Lf\n",ans);
	return 0;
 }