#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	
	cin>>S;
	int a=0, b=0, c=0;
	int i=0;
	while (i<S.size())
	{
		if (S[i]!='a') break;
		a++;
		i++;
	}
	while (i<S.size())
	{
		if (S[i]!='b') break;
		b++;
		i++;
	}
	while (i<S.size())
	{
		if (S[i]!='c') break;
		c++;
		i++;
	}
	
	if ((a+b+c)!=S.size()) cout<<"NO";
	else
	{
		if (a==0 || b==0) cout<<"NO";
		else if (a==c || b==c) cout<<"YES";
		else cout<<"NO";
	}
}