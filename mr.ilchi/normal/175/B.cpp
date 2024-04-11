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

int n;
int sc[2000];
string s[2000];
map <string,int> mp;

void print (string s, int a, int b){
	
	cout << s << ' ';

	if (b==0){
		cout << "pro" << endl;
		return;
	}

	if (a*2 < b) { cout << "noob" << endl; return; }

	if (a*5 < b*4) { cout << "random" << endl; return; }

	if (a*10 < b*9) { cout << "average" << endl; return; }

	if (a*100 < b*99) { cout << "hardcore" << endl; return; }

	cout << "pro" << endl;
}

int main(){

	int cnt = 0;

	cin >> n;

	for (int i=1; i<=n; i++){
		cin >> s[i] >> sc[i];
		if (mp.count(s[i])==0)
			mp[s[i]] = sc[i];
		mp[s[i]] = max(mp[s[i]],sc[i]);
	}

	cout << (int)mp.size() << endl;

	vector <int> Q;

	for (map <string, int> :: iterator it = mp.begin(); it!=mp.end(); it++)
		Q.push_back(it->second);

	for (map < string , int> :: iterator it = mp.begin(); it!=mp.end(); it++){
		
		int f = (it->second);

		int Count = 0;

		for (int i=0; i<(int)Q.size(); i++) if (Q[i]<=f)
			Count ++;

		print (it->first , Count , (int)Q.size());
	}

	return 0;
}