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
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n,k;
LL val[1<<20];

int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++){
		string s; cin >> s;
		for (int j=0; j<(int)s.size(); j++) if (s[j]=='.') s[j] = ' ';
		istringstream inp(s);
		LL a,b,c,d;
		inp >> a >> b >> c >> d;
		val[i] = (a<<24) + (b<<16) + (c<<8) + d;
	}
	LL mask = 0;
	for (int i=1; i<=32; i++){
		mask+= (1LL<<(32-i));
		vector <LL> Q;
		for (int j=0; j<n; j++) 
			Q.push_back(mask & val[j]);
		sort(Q.begin(),Q.end());
		if (unique(Q.begin(),Q.end())-Q.begin() == k){
			cout << ((mask>>24) & (255)) << '.'; 
			cout << ((mask>>16) & (255)) << '.';
			cout << ((mask>>8) & (255))<< '.';
			cout << ((mask) & 255) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}