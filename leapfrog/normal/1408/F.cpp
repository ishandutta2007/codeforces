//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
pair<int,int>p[1000005];int pc,n;
inline void add(int x,int y) {p[++pc]=make_pair(x,y);}
inline void work(int x,int y)
{
	int md=(x+y)>>1;if(x>=y) return;else work(x,md),work(md+1,y);
	for(int i=x;i<=md;i++) add(i,i+md-x+1);
}
int main()
{
	read(n);int cnt=0,tmp=n;while(tmp!=1) tmp>>=1,cnt++;
	work(1,1<<cnt),work(n-(1<<cnt)+1,n),printf("%d\n",pc);
	for(int i=1;i<=pc;i++) printf("%d %d\n",p[i].first,p[i].second);
	return 0;
}