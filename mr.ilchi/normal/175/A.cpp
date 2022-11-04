/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

string s;

int get (string s){
	if (s.size()>7)
		return -1;
	if (s[0]=='0' && s.size()>1)
		return -1;
	int ret = 0;
	for (int i=0; i<(int)s.size(); i++)
		ret = ret * 10 + s[i] - '0';

	if (ret>1000000)
		ret = -1;
	return ret;
}

int main(){

	cin >> s;

	int n = (int)s.size();

	int sum=-1;

	for (int j=1; j<n; j++)
		for (int z=j+1; z<n; z++){
			string s1 = s.substr(0,j);
			string s2 = s.substr(j,z-j);
			string s3 = s.substr(z,n-z);
			int a = get(s1);
			int b = get(s2);
			int c = get(s3);
			if (a!=-1 && b!=-1 && c!=-1)
				sum = max(sum , a+b+c);
		}

	cout << sum << endl;

	return 0;
}