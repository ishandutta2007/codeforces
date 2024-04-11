/*
5 3 5
6 4
2
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int h12,h13,h14,h23,h24,h34;
int len;
int b2,b3,b4;
int al3;
int bl3;
int br3;
int x,y,z;

inline void puta(int x)
{
	assert(x>=0);
	for(int i=0;i<x;i++)
	{
		putchar('a');
	}
}

inline void putb(int x)
{
	assert(x>=0);
	for(int i=0;i<x;i++)
	{
		putchar('b');
	}
}

void print()
{
	cout<<len<<endl;
	for(int i=0;i<len;i++)
	{
		putchar('a');
	}
	puts("");
	
	for(int i=0;i<len;i++)
	{
		if(i<b2) putchar('b');else putchar('a');
	}
	puts("");
	
	for(int i=0;i<al3;i++)
	{
		putchar('a');
	}
	for(int i=0;i<b3;i++)
	{
		putchar('b');
	}
	for(int i=0;i<len-al3-b3;i++)
	{
		putchar('a');
	}
	puts("");
	
	puta(x);
	putb(al3-x);
	puta(y);
	putb(bl3-y);
	puta(z);
	putb(br3-z);
	putb(b4-(al3-x)-(bl3-y)-(br3-z));
	puta(len-x-y-z-(br3-z)-(bl3-y)-(al3-x)-(b4-(al3-x)-(bl3-y)-(br3-z)));
	puts("");
}

inline int check()
{
	int k1=h24-b4+al3+bl3;
	if(k1&1) return inf;
	x=k1/2-y;
	if(x<0) return inf;
	if(x>al3) return inf;
	
	int k2=h34-b4+bl3+br3;
	if(k2&1) return inf;
	z=k2/2-y;
	if(z<0) return inf;
	if(z>br3) return inf;
	
	int br4=b4-(al3-x)-(bl3-y)-(br3-z);
	if(br4<0) return inf;
	return len=max(len,h12+br3+br4);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>h12>>h13>>h14>>h23>>h24>>h34;
	b2=h12;
	b3=h13;
	b4=h14;
	chmax(len,b2);
	chmax(len,b3);
	chmax(len,b4);
	
	if((-h23+b2+b3) & 1) over("-1");
	if((-h23+b2+b3)<0) over("-1");
	bl3=(-h23+b2+b3)/2;
	al3=b2-bl3;
	chmax(len,h12+br3);
	br3=b3-bl3;
	
	int res=inf,k=-1,tlen=len;
	for(y=0;y<=bl3;y++)
	{
		len=tlen;
		int t=check();
		if(t<res)
		{
			res=t;
			k=y;
		}
	}
	y=k;
	if(y==-1) over("-1");
	len=tlen;
	len=check();
	print();
	return 0;
}