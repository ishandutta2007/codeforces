//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}mt19937 rnd(time(0));
int n,K,sm,dep,nw;char c[15];queue<int>q;
inline char qry(int x,int l,int r) {return printf("? %d %d %d\n",l,x,r),fflush(stdout),scanf("%s",c),*c=='Y';}
inline char chk(int x,int y) {int cnt=0;for(int i=1;i<=n;i++) if(x!=i&&y!=i) if(qry(i,x,y)) cnt++,q.push(i);return cnt==dep*2-3;}
inline char ds(int x,int y) {int cnt=0;for(int i=1;i<=n;i++) if(x!=i&&y!=i) cnt+=qry(i,x,y);return cnt==dep-2;}
inline pair<int,int>gt() {int x=rnd()%n+1,y=rnd()%n+1;if(x==y) y=y%n+1;return make_pair(x,y);}
int main()
{
	read(n),read(K),sm=0,dep=0,nw=1;while(sm<n) sm+=nw,dep++,nw*=K;
	pair<int,int>rs;for(rs=gt();!chk(rs.first,rs.second);rs=gt()) while(!q.empty()) q.pop();
	while(!q.empty()) if(ds(rs.first,q.front())) return printf("! %d\n",q.front()),0;else q.pop();
	return 0;
}