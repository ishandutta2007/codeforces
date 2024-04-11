#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

int main() {
	long long n, m;
	cin>>n>>m;
	bool diags = n>0 && m>0 && pow(n*n + m*m, 0.5) + max(n,m) > 2 * pow(max(n,m)*max(n,m) + (min(n,m)-1)*(min(n,m)-1), 0.5);
	if (diags) {
		cout<<n<<" "<<m<<endl;
		cout<<0<<" "<<0<<endl;
		if (m >= n) {
			cout<<0<<" "<<m<<endl;
			cout<<n<<" "<<0<<endl;
		} else {
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<m<<endl;
		}
	} else {
		bool first = (n < m && n!=0) || m == 0;
		cout<<n - (first?1:0)<<" "<<m - (first?0:1)<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<n<<" "<<m<<endl;
		cout<<(first?1:0)<<" "<<(first?0:1)<<endl;
	}
	return 0;
}