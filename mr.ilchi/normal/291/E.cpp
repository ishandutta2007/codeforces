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

int n;
int next[1<<20],p[1<<20];
string t;
string s[1<<20];
vector <int> adj[1<<20];

inline int go (int v, int match){
	int ret = 0;
	for (int i=0; i<(int)s[v].size(); i++){
		while (match!=0 && s[v][i]!=t[match])
			match = next[match-1];
		if (s[v][i]==t[match])
			match++;
		if (match == (int)t.size()){
			ret++;
			match = next[match-1];
		}
	}
	for (int i=0; i<(int)adj[v].size(); i++)
		ret+= go(adj[v][i], match);
	return ret;
}

int main(){
	cin >> n;
	s[0] = "";
	for (int i=1; i<n; i++){
		cin >> p[i] >> s[i]; p[i]--;
		adj[p[i]].push_back(i);
	}
	cin >> t;
	int match = 0;
	next[0] = 0;
	for (int i=1; i<(int)t.size(); i++){
		while (match!=0 && t[i]!=t[match])
			match = next[match-1];
		if (t[i]==t[match])
			match++;
		next[i] = match;
	}
	cout << go(0, 0) << endl;
	return 0;
}