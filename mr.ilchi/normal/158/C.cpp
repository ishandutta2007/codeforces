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

int n;

int main(){
	
	cin >> n;

	vector <string> Q;
	
	for (int o=1; o<=n; o++){
		string ord; cin >> ord;
		if (ord=="pwd"){
			cout << '/';
			for (int i=0; i<(int)Q.size(); i++)
				cout << Q[i] << '/';
			cout << endl;
		}
		else{
			string path; cin >> path;
			if (path[0]=='/')
				Q.clear();
			for (int i=0; i<(int)path.size(); i++) if (path[i]=='/') path[i]= ' ';
			istringstream in(path);
			string s;
			while (in >> s){
				if (s == "..")
					Q.pop_back();
				else
					Q.push_back(s);
			}
		}
	}

	return 0;
}