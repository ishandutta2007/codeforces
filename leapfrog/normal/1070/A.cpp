//
#include<bits/stdc++.h>
using namespace std;const int INF=1e9;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct pipipi{int val;pair<int,int>qwq;}ls[5005][505];
int d,s;char v[5005][505];queue<pair<int,int> >q;
inline void paint(pair<int,int>p) {if(~p.first||~p.second) paint(ls[p.first][p.second].qwq),putchar(ls[p.first][p.second].val|48);}
int main()
{
	read(d),read(s);for(int i=0;i<=9;i++) q.push(make_pair(i,i%d)),v[i][i%d]=1,ls[i][i%d]=(pipipi){i,make_pair(-1,-1)};
	while(!q.empty())
	{
		pair<int,int>x=q.front();q.pop();
		if(x.first==s&&x.second==0) return paint(x),putchar('\n'),0;else if(x.first>s) continue;
		for(int i=0;i<=9;i++) if(!v[x.first+i][(x.second*10+i)%d])
		{
			int nx1=x.first+i,nx2=(x.second*10+i)%d;if(nx1>s) continue;
			ls[nx1][nx2]=(pipipi){i,x},q.push(make_pair(nx1,nx2)),v[nx1][nx2]=1;
		}
	}
	return puts("-1"),0;
}