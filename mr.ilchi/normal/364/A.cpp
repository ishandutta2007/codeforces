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

const int MAXV = 40000;

int cnt[MAXV];

int main(){
	int a; cin >> a;
	string s; cin >> s;
	for (int i=0; i<(int)s.size(); i++){
		for (int j=i, sum=0; j<(int)s.size(); j++){
			sum+= s[j]-'0';
			cnt[sum]++;
		}
	}
	if (a == 0){
		int s = 0;
		for (int i=0; i<MAXV; i++)
			s+= cnt[i];
		cout << 2LL * s * cnt[0] - (LL)cnt[0] * cnt[0] << endl;
	}else{
		LL res = 0;
		for (int i=1; i<MAXV; i++) if (a%i == 0 && a/i<MAXV)
			res+= (LL)cnt[i] * cnt[a/i];
		cout << res << endl;
	}
	return 0;
}