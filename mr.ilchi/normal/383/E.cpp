/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef complex<double> point;

const int alpha = 24;

int n;
int func[1<<alpha];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		string s; cin >> s;
		int mask = 0;
		for (int i=0; i<(int)s.size(); i++)
			mask|=(1<<(s[i]-'a'));
		func[mask]++;
	}
	for (int i=0; i<alpha; i++){
		for (int mask = 0; mask < (1<<(alpha-1)); mask++){
			int cur = ((mask>>i)<<(i+1))+(1<<i)+(mask&((1<<i)-1));
			func[cur]+= func[cur ^ (1<<i)];
		}
	}
	int ret = 0;
	for (int mask = 0; mask < (1<<alpha); mask++)
		ret = ret ^ ((n-func[mask]) * (n-func[mask]));
	cout << ret << endl;
	return 0;
}