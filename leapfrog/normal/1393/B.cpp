#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
struct node{int x,w;bool operator<(node b) const {return w>b.w||(w==b.w&&x<b.x);}};
int n,a[100005];set<node>s;map<int,int>m;
inline void ins(int x) {if(m[x]>0) s.erase((node){x,m[x]});m[x]++,s.insert((node){x,m[x]});}
inline void del(int x) {s.erase((node){x,m[x]}),m[x]--;if(m[x]) s.insert((node){x,m[x]});}
inline char getc() {char c=getchar();while(c!='+'&&c!='-') c=getchar();return c;}
int main()
{
	scanf("%d",&n),s.clear(),m.clear();char c;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),ins(x);
	int zk;scanf("%d",&zk);
	for(int i=1,d;i<=zk;i++)
	{
		c=getc(),scanf("%d",&d);
		if(c=='+') ins(d);else del(d);
		int x,y,z;
		if(s.begin()!=s.end())
		{
			x=(*(s.begin())).w;
			if(++s.begin()!=s.end())
			{
				y=(*(++s.begin())).w;
				if(++(++s.begin())!=s.end()) z=(*(++(++s.begin()))).w;else z=0;
			}
			else y=0;
		}
		else x=0;
//		for(set<node>::iterator i=s.begin();i!=s.end();i++) printf("%d , %d\n",(*i).x,(*i).w);
//		printf("%d , %d , %d\n",x,y,z);
		if(x<4) {puts("NO");continue;}else x-=4;
//		printf("%d , %d , %d , %d\n",!!(y>=2),!!(z>=2),!!(x>=2),(!!(y>=2)+!!(z>=2)+!!(x>=2)));
		if((!!(y>=2)+!!(z>=2)+!!(x>=2))>=2) puts("YES");
		else if((!!(y>=4)+!!(z>=4)+!!(x>=4))>=1) puts("YES");
		else puts("NO");
	}
	return 0;
}