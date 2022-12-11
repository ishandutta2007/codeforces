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

char str[1000001];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n=gi(),i,j,now,s=(1<<26)-1,m,ans=0;char c;
	for (i=1;i<n;i++) {
		while ((c=getchar())!='.'&&c!='!'&&c!='?');
		scanf("%s",str+1);
		m=strlen(str+1);
		now=0;
		for (j=1;j<=m;j++) now|=1<<(str[j]-'a');
		if (!(s^(s&-s))) ans+=c=='?'||c=='!';
		else
			if (c=='!') s&=now;
			else if (c=='.') s&=~now;
			else s&=~now;
	}
	cout<<ans<<endl;
	return 0;
}