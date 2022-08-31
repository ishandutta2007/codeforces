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

typedef long long int64;
typedef long double real;
typedef pair<int,int> pii;

#define X first
#define Y second

const int MaxN=100010;

int a,b,n;
string s;

int main()
{
	cin>>a>>b>>n;
	int t=a%b;
	for (int i=1;i<=n;++i)
	{
		t=t*10%b;
		for (int x=0;x<=9;++x)
			if ((t+x)%b==0)
			{
				s+=(char)(x+48);
				t=0;
				break;
			}
		if (t)
		{
			puts("-1");
			return 0;
		}
	}
	cout<<a<<s<<endl;
	return 0;
}