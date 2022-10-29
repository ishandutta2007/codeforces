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

const int maxn = 210000;

int n;
char S[maxn],T[maxn];
struct Str
{
	int rs[maxn],pre[maxn];
}s1,s2;
int rs[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%s",S+1); n=strlen(S+1);
	for(int i=1;i<=n;i++)
	{
		s1.pre[i]=s1.pre[i-1]+(S[i]!='A');
		s1.rs[i]=S[i]=='A'?1+s1.rs[i-1]:0;
	}
	scanf("%s",T+1); n=strlen(T+1);
	for(int i=1;i<=n;i++)
	{
		s2.pre[i]=s2.pre[i-1]+(T[i]!='A');
		s2.rs[i]=T[i]=='A'?1+s2.rs[i-1]:0;
	}
	int m; scanf("%d",&m);
	while(m--)
	{
		int al,ar,bl,br; scanf("%d%d%d%d",&al,&ar,&bl,&br);
		int AA=min(s1.rs[ar],ar-al+1);
		int AB=s1.pre[ar]-s1.pre[al-1];
		int BA=min(s2.rs[br],br-bl+1);
		int BB=s2.pre[br]-s2.pre[bl-1];
		
		if(AB==0&&BB!=0)
		{
			AB+=2; AA--;
			if(AA>BA) AA=BA;
		}
		if(AA>BA&&AA%3!=BA%3) AA=BA,AB+=2;
		
		if(AA>=BA&&AB<=BB&&AB%2==BB%2) putchar('1');
		else putchar('0');
	}
	
	return 0;
}