#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void read(int &x)
{
	char c;
	while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 110;

int n,x;
int a[maxn];
int v[maxn];

int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]]++;
	
	int ans=0;
	for(int i=0;i<x;i++)
		if(!v[i]) ans++;
	ans+=v[x];
	printf("%d\n",ans);
	
	return 0;
}