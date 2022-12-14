#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int q,n;
string s;
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n>>s;
		if (n==2 && s[0]>=s[1]) 
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("2\n");
		printf("%d ",s[0]-'0');
		for (int i=1;i<n;i++) printf("%d",s[i]-'0');
		printf("\n");
	}
	return Accepted;
}