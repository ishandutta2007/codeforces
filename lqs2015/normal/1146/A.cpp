#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,ans;
string s;
int main()
{
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++)
	{
		if (s[i]=='a') ans++;
	}
	cout<<min(ans*2-1,n)<<endl;
	return Accepted;
}