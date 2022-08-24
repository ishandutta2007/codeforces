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

const int MAX_N=1010000;

const int INF=1000000000;

string s;

ll res;



ll solveL(int x)
{
	ll res=0;
	int now=x;
	while (now>0 && ( isdigit(s[now-1]) || isalpha(s[now-1]) || s[now-1]=='_'))
	{
		--now;
		if ( isalpha(s[now]))
			++res;
	}
	return res;
}

ll solveR(int x)
{
	ll res=0;
	int now=x;
	if (now+1>=s.size() || s[now+1]=='.')
		return 0;
	while (now+1<s.size() && (  isalpha( s[now+1] ) || isdigit( s[now+1] ) || s[now+1]=='.'  ))
	{
		++now;
		if (s[now]=='.')
			break;
	}
	
	if (s[now]!='.')
		return 0;
	

	while (now+1<s.size() && ( isalpha( s[now+1] ) ) )
	{
		++now;
		++res;
	}
	
	return res;
}


int main()
{
	cin>>s;
	
	for (int i=0;i<s.size();++i)
	{
		if (s[i]=='@')
		{
			res+=solveL(i)*solveR(i);
			//cout<<solveL(i)<<" "<<solveR(i)<<"\n";
		}
	}
	cout<<res;
}