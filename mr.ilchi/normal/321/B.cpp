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

int n,m;

int main(){
	cin >> n >> m;
	vector <int> attack,defense;
	for (int i=0; i<n; i++){
		string temp; cin >> temp;
		if (temp == "ATK") { int fx; cin >> fx; attack.push_back (fx); }
		if (temp == "DEF") { int fx; cin >> fx; defense.push_back(fx); }
	}
	vector <int> Q;
	for (int i=0; i<m; i++){
		int fx; cin >> fx;
		Q.push_back(fx);
	}
	sort(Q.begin(), Q.end());
	sort(attack.begin(), attack.end());
	sort(defense.begin(), defense.end());
	int ret = 0;
	for (int i=1; i<=min((int)attack.size(), (int)Q.size()); i++){
		int s1=0,s2=0;
		vector <int> f1; for (int j=0; j<i; j++) { f1.push_back(attack[j]); s1+= f1.back(); }
		vector <int> f2; for (int j=0; j<i; j++) { f2.push_back(Q[(int)Q.size()-i+j]); s2+= f2.back(); }
		bool bad = false;
		for (int j=0; j<i; j++) if (f1[j] > f2[j])
			bad = true;
		if (!bad)
			ret = max(ret, s2-s1);
	}
	for (int i=0; i<(int)defense.size(); i++){
		bool f = false;
		for (int j=0; j<(int)Q.size(); j++) if (Q[j]>defense[i]){
			f = true;
			Q.erase(Q.begin()+j);
			break;
		}
		if (!f){
			cout << ret << endl;
			return 0;
		}
	}

	if (attack.size() > Q.size()){
		cout << ret << endl;
		return 0;
	}
	
	int s1=0,s2=0;
	vector <int> f1; for (int j=0; j<(int)attack.size(); j++) { f1.push_back(attack[j]); s1+= f1.back(); }
	vector <int> f2; for (int j=0; j<(int)attack.size(); j++) { f2.push_back(Q[(int)Q.size()-(int)attack.size()+j]); s2+= f2.back(); }
	bool bad = false;
	for (int j=0; j<(int)attack.size(); j++) if (f1[j] > f2[j])
		bad = true;
	if (!bad){
		s2 = 0;
		for (int j=0; j<(int)Q.size(); j++)
			s2+= Q[j];
		ret = max(ret, s2-s1);	
	}
	cout << ret << endl;
	return 0;
}