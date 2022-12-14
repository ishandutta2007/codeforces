#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,b,g,ans;
int main()
{
	cin>>b>>g>>n;
	for (int i=0;i<=n;i++)
	{
		if (i<=b && n-i<=g) ans++;
	}
	printf("%d\n",ans);
	return Accepted;
}