#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

char s[20][20];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	char c;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++) {
			while ((c=getchar())!='.'&&c!='x'&&c!='o');
			s[i][j]=c;
		}
	int x=gi(),y=gi();
	x=(x-1)%3,y=(y-1)%3;
	bool flag=false;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++) {
			if (s[x*3+i][y*3+j]=='.') flag=true;
		}
	if (flag) {
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (s[x*3+i][y*3+j]=='.')
				s[x*3+i][y*3+j]='!';
		
	}
	else for (int i=1;i<=9;i++)
			 for (int j=1;j<=9;j++)
				 if (s[i][j]=='.') s[i][j]='!';
	for (int i=1;i<=9;i++,putchar(10)) {
		for (int j=1;j<=9;j++) {
			putchar(s[i][j]);
			if (j==3||j==6) putchar(' ');
		}
		if (i==3||i==6) putchar(10);
	}
	return 0;
}