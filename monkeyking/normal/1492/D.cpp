#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#define ll long long 
#define pii pair<int,int>
template <typename T> inline void chmin(T &x,const T &b) {x=(x<b?x:b);}
template <typename T> inline void chmax(T &x,const T &b) {x=(x>b?x:b);}
using namespace std;
int a,b,k;

inline void put(char c,int t)
{
	while(t--) putchar(c);
}

inline void fail()
{
	puts("No");
	exit(0);
}

int t[200005];
int main()
{
	cin>>a>>b>>k;
	if(b==1 || a==0)
	{
		if(k!=0) fail();
		puts("YES");
		put('1',b);
		put('0',a);
		puts("");
		put('1',b);
		put('0',a);
		puts("");
		return 0;
	}
	if(k>a+b-2) fail();
	puts("YES");
	put('1',b);
	put('0',a);
	puts("");
	for(int i=0;i<b;i++) t[i]=1;
	for(int i=b;i<a+b;i++) t[i]=0;
	int curpos=b-1;
	while(k>0)
	{
		k--;
		swap(t[curpos],t[curpos+1]);
		curpos++;
		if(curpos==a+b-1) break;
	}
	curpos=b-1;
	while(k>0)
	{
		k--;
		swap(t[curpos-1],t[curpos]);
		curpos--;
	}
	for(int i=0;i<a+b;i++) putchar(t[i]+'0');
	puts("");
	return 0;
}