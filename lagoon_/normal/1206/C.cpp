#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re int n;
	re long long ans=0;
	scanf("%d",&n);
	if(n&1)
	{
		puts("YES");
		for(re int i=1;i<=n;i++)printf("%d ",(i-1)*2+(!(i&1))+1);
		for(re int i=1;i<=n;i++)printf("%d ",(i-1)*2+(i&1)+1);
	}
	else puts("NO");
}