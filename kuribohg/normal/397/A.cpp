#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,used[101],l,r,li,ri,ans;
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&li,&ri);
		for(int i=li;i<ri;i++) used[i]=true;
	}
	for(int i=l;i<r;i++)
		if(!used[i]) ans++;
	printf("%d\n",ans);
	return 0;
}