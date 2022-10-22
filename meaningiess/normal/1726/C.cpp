#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[200010];
int lst[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,s=0,ans=0;cin>>n;
		cin>>a+1;
		for (i=0;i<=2*n;i++) lst[i]=0;
		for (i=1;i<=2*n;i++)
		{
			if (a[i]=='(')
			{
				if (!lst[s]) ans++;
				lst[s]=i;
				s++;
			}
			else
			{
				lst[s]=0;
				s--;
			}
		}
		cout<<ans<<endl;
	}
}