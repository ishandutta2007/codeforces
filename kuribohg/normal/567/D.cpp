#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,k,a,Q,res;
set<int> S;
int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&Q);
	S.insert(0),S.insert(n+1);
	res=(n+1)/(a+1);
	for(int ans=1;ans<=Q;ans++)
	{
		int x;
		scanf("%d",&x);
		if(S.count(x)) continue;
		set<int>::iterator pre=S.lower_bound(x);
		set<int>::iterator nxt=S.upper_bound(x);
		pre--;
		res-=((*nxt)-(*pre))/(a+1);
		res+=((*nxt)-x)/(a+1);
		res+=(x-(*pre))/(a+1);
		if(res<k) {printf("%d\n",ans);return 0;}
		S.insert(x);
	}
	puts("-1");
	return 0;
}