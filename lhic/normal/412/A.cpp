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

string s;
int n,k;

int main()
{
	cin>>n>>k;
	cin>>s;
	
	if (k-1 > n-k)
	{
		for (int i=k;i<n;++i)
			cout<<"RIGHT\n";
		for (int i=n;i>1;--i)
		{
			cout<<"PRINT "<<s[i-1]<<"\n";
			cout<<"LEFT\n";
		}
		cout<<"PRINT "<<s[0];
	}
	else
	{
		for (int i=k;i>1;--i)
			cout<<"LEFT\n";
		for (int i=1;i<n;++i)
		{
			cout<<"PRINT "<<s[i-1]<<"\n";
			cout<<"RIGHT\n";
		}
		cout<<"PRINT "<<s[n-1];
	}
	
}