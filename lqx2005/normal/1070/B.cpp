// Problem: B. Berkomnadzor
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1070/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int unsigned
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(char&ch){
   int s=0;
   ch=getchar();
   while(ch<'0'||ch>'9')ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}
int val[1000003],sz[1000003],tot;
void flush()
{
	printf("%u\n",tot);
	for(int i=1; i<=tot; ++i) 
		printf("%u.%u.%u.%u/%u\n",
		(val[i]>>24)&255,(val[i]>>16)&255,(val[i]>>8)&255,val[i]&255,32-sz[i]);
	return ;
}
int ls[10000003],rs[10000003];
bool e0[10000003],e1[10000003];
//exist
bool a0[10000003],a1[10000003];
//all
bool f0[10000003],f1[10000003];
int cnt=1;
//any,all
void insert(int v,int d,bool op,int td=32,int id=1)
{
	if(d==td) 
	{
		if(op) f1[id]=e1[id]=a1[id]=1;
		else f0[id]=e0[id]=a0[id]=1;
		return ;
	}
	if(op&&a1[id]) return ;
	if(!op&&a0[id]) return ;
	if(v&(1u<<(td-1)))
		(!rs[id])&&(rs[id]=++cnt),insert(v,d,op,td-1,rs[id]);
	else
		(!ls[id])&&(ls[id]=++cnt),insert(v,d,op,td-1,ls[id]);
	if(op)
		e1[id]=e1[ls[id]]|e1[rs[id]],
		a1[id]=a1[ls[id]]&a1[rs[id]];
	else
		e0[id]=e0[ls[id]]|e0[rs[id]],
		a0[id]=a0[ls[id]]&a0[rs[id]];
	return ;
}
void update()
{
	int v=0;
	char ch=getchar();
	while(ch!='-'&&ch!='+') ch=getchar();
	bool ovo=0;
	if(ch=='-') ovo=1;
	v=read(ch),v<<=8,v+=read(ch),v<<=8,v+=read(ch),v<<=8,v+=read(ch);
	int d=0;
	if(ch=='/') d=32-read(ch);
	insert(v,d,ovo);
	return ;
}
void build(int d=32,int v=0,int id=1)
{
	if(!e1[id]) return ;
	if(!e0[id]){val[++tot]=v,sz[tot]=d;return ;}
	if(a1[id])
	{
		if(e0[id]) puts("-1"),exit(0);
	}
	if(a0[id])
	{
		if(e1[id]) puts("-1"),exit(0);
		return ;
	}
	build(d-1,v,ls[id]),
	build(d-1,v+(1u<<(d-1)),rs[id]);
}
signed main()
{
	char ch;
	for(int T=read(ch); T--;) update();
	build(),flush();
	return 0;
}