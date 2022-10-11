#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
using namespace std;
int num_of_dig(long long n)
{
	ostringstream con;
	con << n;
	string s=con.str();
	return s.size();
}
bool is_trailing(string s,int ind)
{
	int i;
	for (i=ind;i<s.size();i++)
	{
		if (s[i]!='9')
		return false;
	}
	return true;
}
long long solve(long long n,int ind)
{
	int i;
	ostringstream con;
	con << n;
	if (is_trailing(con.str(),ind))
	return n;
	string s=con.str();
	s[ind]--;
	for (i=ind+1;i<s.size();i++)
	s[i]='9';
	return atoll(s.c_str());
}
int num_of_trailing(long long n)
{
	int ans=0;
	while (n%10==9)
	{
		n/=10;
		ans++;
	}
	return ans;
}
int main()
{
	int i;
	long long n,d,maxi;
	cin >> n >> d;
	maxi=n;
	for (i=0;i<num_of_dig(n);i++)
	{
		if (n-solve(n,i)<=d && solve(n,i)%10==9)
		{
			if (num_of_trailing(solve(n,i))>num_of_trailing(maxi))
			maxi=solve(n,i);
			else if (num_of_trailing(solve(n,i))==num_of_trailing(maxi))
			{
				if (n-solve(n,i)<n-maxi)
				maxi=solve(n,i);
			}
		}
	}
	cout << maxi;
}