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

int cnt[100];

int main(){
	string s; cin >> s;
	int n; cin >> n;
	for (int i=0; i<(int)s.size(); i++)
		cnt[s[i]-'a']++;
	int d = 0;
	for (int i=0; i<26; i++) if (cnt[i]>0)
		d++;
	if (d > n){
		cout << -1 << endl;
		return 0;
	}
	for (int rep=1; true; rep++){
		int len = 0;
		for (int i=0; i<26; i++)
			len+= (cnt[i]+rep-1) / rep;
		if (len > n)
			continue;
		string ret = "";
		for (int i=0; i<26; i++) if (cnt[i])
			ret+= string((cnt[i]+rep-1)/rep, char('a'+i));
		while ((int)ret.size()<n)
			ret+="a";
		cout << rep << endl << ret << endl;
		return 0;
	}
	return 0;
}