#include <bits/stdc++.h>
using namespace std;
const int INF=100000000;
int n;
string s;
int main()
{
	cin>>n>>s;
	int ans=INF;
	for(int i=3;i<n;i++)
	{
		int sum=0;
		sum+=min(abs(s[i]-'G'),26-abs(s[i]-'G'));
		sum+=min(abs(s[i-1]-'T'),26-abs(s[i-1]-'T'));
		sum+=min(abs(s[i-2]-'C'),26-abs(s[i-2]-'C'));
		sum+=min(abs(s[i-3]-'A'),26-abs(s[i-3]-'A'));
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}