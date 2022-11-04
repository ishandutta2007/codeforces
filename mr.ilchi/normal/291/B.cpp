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

int main(){
	string s; getline(cin, s);
	s+= " ";
	string past = "";
	bool open = false;
	for (int i=0; i<(int)s.size(); i++){
		if (s[i]=='\"'){
			if (open)
				cout << "<" + past << ">" << endl;
			open = !open;
			past = "";
		}
		else if (s[i]== ' '){
			if (open)
				past+= " ";
			else if (!past.empty()){
				cout << "<" << past << ">" << endl;
				past = "";
			}
		}
		else
			past+= s[i];
	}
	return 0;
}