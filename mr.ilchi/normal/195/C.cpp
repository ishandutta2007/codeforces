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

const string bad = "()\",";

int n;

int main(){
	
	cin >> n;

	string ord; getline(cin,ord);

	int hei = 0 , pos = -1;
	string sss = "";

	for (int i=1; i<=n; i++){
		getline(cin,ord);
		string oo = ord;
		for (int j=0; j<(int)ord.size(); j++) if (bad.find(ord[j])!=bad.npos) 
			oo[j] = ' ';
		istringstream inp(oo);
		string ss;	
		vector <string> Q;
		while (inp >> ss)
			Q.push_back(ss);
		if (Q.empty())
			continue;
		if (Q[0] == "try")
			hei++;
		if (Q[0] == "throw"){
			pos = hei;
			sss = Q[1];
		}
		if (Q[0] == "catch"){
			if (pos>=hei && Q[1]==sss){
				int x = ord.find('\"');
				int y = ord.find('\"',x+1);
				cout << ord.substr(x+1,y-x-1) << endl;
				return 0;
			}
			hei--; pos=min(pos,hei);
		}
	}

	cout << "Unhandled Exception" << endl;

	return 0;
}