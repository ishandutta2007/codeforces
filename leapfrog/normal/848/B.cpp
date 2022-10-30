//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int pos,tim,id;bool operator<(node a) const {return pos<a.pos;}}u[100005],r[100005];
int m,w,h,ut=0,rt=0,T[100005];pair<int,int>mdzz[100005];map<int,int>lsh;
vector<node>qr[100005];deque<int>qwqr[100005];
int main()
{
	read(m),read(w),read(h);
	for(int i=1,fg;i<=m;i++)
	{
		read(fg),fg=fg^1;
		if(fg&1) read(r[++rt].pos),read(r[rt].tim),r[rt].id=i;
		else read(u[++ut].pos),read(u[ut].tim),u[ut].id=i;
	}
	int cnt=0;for(int i=1;i<=rt;i++) T[i]=r[i].pos-r[i].tim;
	sort(T+1,T+rt+1);for(int i=1;i<=rt;i++) if(!lsh[T[i]]) lsh[T[i]]=++cnt;
	for(int i=1;i<=rt;i++) qr[lsh[r[i].pos-r[i].tim]].push_back(r[i]);
	for(int i=1;i<=cnt;i++)
	{
		sort(qr[i].begin(),qr[i].end());
		for(int j=0;j<(int)qr[i].size();j++) qwqr[i].push_back(qr[i][j].id);
	}
	sort(u+1,u+ut+1);
	for(int i=1;i<=ut;i++)
	{
		int id=lsh[u[i].pos-u[i].tim];
		if(!id||qwqr[id].empty()) {mdzz[u[i].id]=make_pair(u[i].pos,h);continue;}
		mdzz[qwqr[id].back()]=make_pair(u[i].pos,h);
		qwqr[id].pop_back(),qwqr[id].push_front(u[i].id);
	}
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<(int)qr[i].size();j++)
		{
			mdzz[qwqr[i].front()]=make_pair(w,qr[i][j].pos);
			qwqr[i].pop_front();
		}
	for(int i=1;i<=m;i++) printf("%d %d\n",mdzz[i].first,mdzz[i].second);
	return 0;
}