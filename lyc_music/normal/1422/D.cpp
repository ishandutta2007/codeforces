//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int n,m,sx,sy,fx,fy,disT[100005],head[100005],cnt;

struct qwq
{
	int x,y,z;
}c[100005];

priority_queue<pair<int,int> >q;
pair<int,int>now;

struct 
{
	int to,val,nx;
}e[1000005];

void ad(int x,int y,int z)
{
	e[++cnt].to=y;
	e[cnt].val=z;
	e[cnt].nx=head[x];
	head[x]=cnt;
}

void dij()
{
	for (int i=1;i<=m+1;i++) disT[i]=INT_MAX;
	q.push(make_pair(0,0));
	while (!q.empty())
	{
		now=q.top();
		q.pop();
		now.first=-now.first;
		if (now.first>disT[now.second]) continue;
		for (int i=head[now.second];i;i=e[i].nx)
		 if (disT[now.second]+e[i].val<disT[e[i].to])
		 {
		 	disT[e[i].to]=disT[now.second]+e[i].val;
		 	q.push(make_pair(-disT[e[i].to],e[i].to));
		 }
	}
}

bool Cmp(qwq x,qwq y)
{
	return x.x<y.x;
}

bool Cmp1(qwq x,qwq y)
{
	return x.y<y.y;
}

signed main()
{
	n=read(),m=read();
	sx=read(),sy=read(),fx=read(),fy=read();
	ad(0,m+1,abs(fx-sx)+abs(fy-sy));
	for (int i=1;i<=m;i++) c[i].x=read(),c[i].y=read(),c[i].z=i;
	sort(c+1,c+m+1,Cmp);
	for (int i=2;i<=m;i++)
	  ad(c[i].z,c[i-1].z,c[i].x-c[i-1].x),ad(c[i-1].z,c[i].z,c[i].x-c[i-1].x);
	sort(c+1,c+m+1,Cmp1);
	for (int i=2;i<=m;i++)
	  ad(c[i].z,c[i-1].z,c[i].y-c[i-1].y),ad(c[i-1].z,c[i].z,c[i].y-c[i-1].y);
	for (int i=1;i<=m;i++)
	{
		ad(0,c[i].z,min(abs(c[i].x-sx),abs(c[i].y-sy)));
		ad(c[i].z,m+1,abs(fx-c[i].x)+abs(fy-c[i].y));
	}
	dij();
	writeln(disT[m+1]);
}