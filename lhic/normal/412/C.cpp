#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N=101000;

const int INF=1000000000;

int ans[MAX_N];

int n;

string s;
int main()
{
	int l;
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		s="";
		cin>>s;
		l=s.size();
		for (int j=0;j<s.size();++j)
		{
			if (s[j]!='?' && ans[j]!='?' && ans[j] && ans[j]!=s[j])
				ans[j]='?';
			else if (s[j]!='?' && ans[j]!='?' && ans[j]!=s[j])
				ans[j]=s[j];
		}
	}
	for (int i=0;i<l;++i)
		if (!ans[i])
			ans[i]='a';
	for (int i=0;i<l;++i)
		cout<<(char)ans[i];
}