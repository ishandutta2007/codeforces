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

string s;
int a,b,n;

inline pii get (char X){
	if (X == 'U') return pii(0,1);
	if (X == 'D') return pii(0,-1);
	if (X == 'L') return pii(-1,0);
	if (X == 'R') return pii(1,0);
	return pii(0,0);
}

int main(){
	cin >> a >> b;
	if (a == 0 && b == 0){
		cout << "Yes" << endl;
		return 0;
	}
	cin >> s;
	n = (int)s.size();
	int totx = 0, toty = 0;
	for (int i=0; i<n; i++){
		totx+= get(s[i]).first;
		toty+= get(s[i]).second;
	}
	if (abs(a)>n && abs(a-totx)>=abs(a)) { cout << "No" << endl; return 0; }
	if (abs(b)>n && abs(b-toty)>=abs(b)) { cout << "No" << endl; return 0; }
	
	int curx = 0, cury = 0;
	if (totx == 0 && toty == 0){
		for (int i=0; i<n; i++){
			curx+= get(s[i]).first;
			cury+= get(s[i]).second;
			if (curx == a && cury == b){
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
		return 0;
	}
	int rep = 0;
	if (abs(a)>n) { rep = max(rep, abs(a)/abs(totx) - n); }
	if (abs(b)>n) { rep = max(rep, abs(b)/abs(toty) - n); }
	curx = totx * rep;
	cury = toty * rep;
	while (true){
		if (abs(a-curx)>n && abs((a-totx)-(curx))>=abs(a-curx)) { cout << "No" << endl; return 0; }
		if (abs(b-cury)>n && abs((b-toty)-(cury))>=abs(b-cury)) { cout << "No" << endl; return 0; }
		for (int i=0; i<n; i++){
			curx+= get(s[i]).first;
			cury+= get(s[i]).second;
			if (curx == a && cury == b){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	return 0;
}