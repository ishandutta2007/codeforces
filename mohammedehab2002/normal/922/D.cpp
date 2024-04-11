#include <iostream>
#include <algorithm>
using namespace std;
string s[100005];
long long go(string s)
{
	long long ans=0;
	int cnt=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='s')
		cnt++;
		else
		ans+=cnt;
	}
	return ans;
}
bool cmp(string a,string b)
{
	return go(a+b)>go(b+a);
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	cin >> s[i];
	sort(s,s+n,cmp);
	for (int i=1;i<n;i++)
	s[0]+=s[i];
	cout << go(s[0]);
}