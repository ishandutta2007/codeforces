#include <iostream>
#include <algorithm>
using namespace std;
int Mod[]={982451579,982451581,982451609,982451629,982451653};
string s[100005];
int main()
{
	int n,k,mod=Mod[rand()%5];
	long long pw=1,sum=0;
	bool qu=0;
	cin >> n >> k;
	for (int i=0;i<=n;i++)
	{
		cin >> s[i];
		if (s[i]=="?")
		{
			qu=1;
			continue;
		}
		sum=(sum+(pw*atoi(s[i].c_str()))%mod+mod)%mod;
		pw=((pw*k)%mod+mod)%mod;
	}
	if (qu)
	{
		if (k)
		{
			if (n%2)
			cout << "Yes";
			else
			cout << "No";
		}
		else if (s[0]=="?")
		{
			if ((n-count(s,s+n+1,"?")+1)%2)
			cout << "Yes";
			else
			cout << "No";
		}
		else if (s[0]=="0")
		cout << "Yes";
		else
		cout << "No";
		return 0;
	}
	if (sum)
	cout << "No";
	else
	cout << "Yes";
}