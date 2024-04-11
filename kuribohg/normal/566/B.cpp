#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=120010;
int n,A[MAXN],B[MAXN],C[MAXN],cnt,c[MAXN];
bool used[MAXN];
vector<int> ans;
bool ok(int x)
{
	bool res=false;
	c[A[x]]--;
	c[B[x]]++;
	c[C[x]]++;
	if(c[B[x]]<=9&&c[C[x]]<=9) res=true;
	c[A[x]]++;
	c[B[x]]--;
	c[C[x]]--;
	return res;
}
int main()
{
	scanf("%d",&n);
	n<<=2;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]),c[i]=4;
	while(cnt<n)
	{
		for(int i=1;i<=n;i++)
			if(!used[i]&&ok(i))
			{
				c[A[i]]--;
				c[B[i]]++;
				c[C[i]]++;
				used[i]=true;
				ans.push_back(i);
				cnt++;
			}
	}
	puts("YES");
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}