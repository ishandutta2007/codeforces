#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
const int MAXN=200010;
int n,ans;
set<int> S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char op[20];
		int x;
		scanf("%s%d",op,&x);
		if(op[0]=='+') S.insert(x),ans=max(ans,(int)S.size());
		else
		{
			if(!S.count(x)) ans++;
			else S.erase(x);
		}
	}
	printf("%d\n",ans);
	return 0;
}