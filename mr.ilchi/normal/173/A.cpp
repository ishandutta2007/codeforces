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

const int maxN = 1000 + 10;

int n,n1,n2,lcm;
int d[maxN];
string s1,s2;
map <char,char> mp; 

int go (int x, int y){
	
	int now = x % n2;

	int tmp = (y-now+n2) % n2;

	if (d[tmp]==-1)
		return 0;

	int round = x + n1 * d[tmp];

	if (round>=n)
		return 0;

	return 1 + ((n-1-round) / lcm);
}

int main(){
	
	mp['R'] = 'S'; mp['S'] = 'P'; mp['P'] = 'R';
	
	cin >> n >> s1 >> s2;
	n1 = (int)s1.size();
	n2 = (int)s2.size();
	int ans1=0,ans2=0;

	memset(d,-1,sizeof d);

	for (int i=0; i<n2; i++){
		int tmp = (i * n1) % n2;
		if (d[tmp]==-1)
			d[tmp] = i;
	}

	lcm = n1 * n2 / __gcd(n1,n2);

	for (int i=0; i<n1; i++)
		for (int j=0; j<n2; j++) if (s1[i]!=s2[j]){
			if (mp[s1[i]]==s2[j])
				ans2+= go(i,j);
			else
				ans1+= go(i,j);
		}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}