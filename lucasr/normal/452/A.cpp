#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

string pos[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
	int n;
	cin>>n;
	string val;
	cin>> val;
	for (int i=0;i<8;i++) {
		if (pos[i].length() == n) {
			bool can = true;
			for (int j=0;j<n;j++) if (pos[i][j] != val[j] && val[j] != '.') can = false;
			if (can) {
				cout<<pos[i]<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}