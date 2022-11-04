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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const string bad = "(),";

int n,m,k;
string s;
map < string , vector < vector <string> > > mp; 
map < string , string> typ;

bool match (const vector <string> &a, const vector <string> &b){
	if (a.size() != b.size())
		return false;
	for (int i=0; i<(int)a.size(); i++) if (b[i]!="T" && a[i]!=b[i])
		return false;
	return true;
}

int main(){

	cin >> n;
	getline(cin,s);
	for (int i=1; i<=n; i++){
		getline(cin,s);
		for (int i=0; i<(int)s.size(); i++) if (bad.find(s[i])!=bad.npos) s[i]=' ';
		istringstream inp(s);
		string tmp;
		string name = "";
		vector <string> Q;
		while (inp>>tmp){
			if (tmp == "void")
				continue;
			if ((int)name.size() == 0){
				name = tmp;
				continue;
			}
			Q.push_back(tmp);
		}
		mp[name].push_back(Q);
	}

	cin >> m; getline(cin,s);
	for (int i=1; i<=m; i++){
		getline(cin,s);
		istringstream inp(s); 
		string f1,f2; 
		inp >> f1 >> f2;
		typ[f2] = f1;
	}

	cin >> k; getline(cin,s);
	for (int i=1; i<=k; i++){
		getline(cin,s);
		for (int i=0; i<(int)s.size(); i++) if (bad.find(s[i])!=bad.npos) s[i]=' ';
		istringstream inp(s);
		string tmp;
		string name = "";
		vector <string> Q;
		bool f = false;
		while (inp >> tmp){
			if ((int)name.size()==0){
				name = tmp;
				continue;
			}
			if (typ.find(tmp)==typ.end()){
				f = true;
				continue;
			}
			Q.push_back(typ[tmp]);
		}
		if (f || mp.find(name)==mp.end()){
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i=0; i<(int)mp[name].size(); i++){
			if (match(Q,mp[name][i]))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}