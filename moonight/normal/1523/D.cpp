#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define gc getchar()
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,V) for(int i=0;i<V.size();++i) 
inline int rd()
{
	int x=0,w=1;char c=gc;
	while(c!='-'&&!isdigit(c))c=gc;
	if(c=='-')w=-1,c=gc;
	while(isdigit(c))x=x*10+c-'0',c=gc;
	return x*w;
}
const int N=400005;
int n,m,p,hn,asz,a[N],b[65],c[N],sz[N];char s[N][65],ans[65];
int main()
{
	n=rd();m=rd();p=rd();hn=(n+1)/2;
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)a[i]=i;
	srand(time(0));
	random_shuffle(a+1,a+n+1);
	rep0(i,1,N)sz[i]=sz[i>>1]+(i&1);
	asz=0;rep(i,1,m)ans[i]='0';
	rep(id,1,100)
	{
		int x=a[id],nn=0;
		rep(i,1,m)if(s[x][i]=='1')b[nn++]=i;
		int nnn=1<<nn;
		rep(i,1,n)
		{
			int t=0;
			rep0(j,0,nn)if(s[i][b[j]]=='1')t|=(1<<j);
			c[t]++;
		}
		rep0(j,0,nn)rep0(i,0,nnn)if(i>>j&1)c[i^(1<<j)]+=c[i];
		rep0(i,0,nnn)if(c[i]>=hn)
		{
			if(sz[i]>asz)
			{
				asz=sz[i];rep(j,1,m)ans[j]='0';
				rep0(j,0,nn)ans[b[j]]='0'+(i>>j&1);
			}
		}
		rep0(i,0,nnn)c[i]=0;
	}
	rep(i,1,m)putchar(ans[i]);
	return 0;
}