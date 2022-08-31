#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int main()
{
	string s;
	int k;
	cin>>s>>k;
	for (int i=0;i<s.size();++i)
	{
		if (s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		if (s[i]-'a'<k)
			s[i]=s[i]-'a'+'A';
	}
	cout<<s;
	return 0;
}