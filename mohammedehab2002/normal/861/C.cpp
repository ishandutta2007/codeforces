#include <iostream>
using namespace std;
pair<int,int> dp[3005];
string s;
bool vowel(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
void go(int ind)
{
	if (ind==0)
	return;
	go(dp[ind].second);
	for (int i=dp[ind].second;i<ind;i++)
	cout << s[i];
	cout << ' ';
}
int main()
{
	cin >> s;
	dp[0]=make_pair(-1,0);
	for (int i=1;i<=s.size();i++)
	{
		dp[i]=make_pair((1<<30),-1);
		string t="";
		for (int x=i-1;x>=0;x--)
		{
			bool b=0;
			if (vowel(s[x]))
			{
				t="";
				b=1;
			}
			else if (t.size()<2)
			{
				b=1;
				t=s[x]+t;
			}
			else if (s[x]==t[0] && s[x]==t[1])
			b=1;
			if (!b)
			break;
			if (dp[i].first>dp[x].first+1)
			dp[i]=make_pair(dp[x].first+1,x);
		}
	}
	go(s.size());
}