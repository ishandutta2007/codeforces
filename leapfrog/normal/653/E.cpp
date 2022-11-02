//Coded by X_qaeq on 2021.11.14 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;
int n,m,K,tmp[N],tmpt;set<int>nw,e[N];
int main()
{
	read(n,m,K);for(int i=1,x,y;i<=m;i++) read(x,y),e[x].insert(y),e[y].insert(x);
	if(n-1-(int)e[1].size()<K) return puts("impossible"),0;
	int cnt=0;for(int i=2;i<=n;i++) nw.insert(i);
	for(int i=2;i<=n;i++) if(nw.count(i))
	{
		queue<int>q;q.push(i),nw.erase(i),cnt++;char fg=0;
		while(!q.empty())
		{
			int x=q.front();q.pop(),tmpt=0,fg|=!e[x].count(1);
			for(auto y:nw) if(!e[x].count(y)) q.push(tmp[++tmpt]=y);
			for(int i=1;i<=tmpt;i++) nw.erase(tmp[i]);
		}if(!fg) return puts("impossible"),0;
	}
	if(cnt>K) return puts("impossible"),0;
	return puts("possible"),0;
}