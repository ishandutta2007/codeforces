#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int N = 1000100;
char buff[N];

bool solve() {

	scanf("%s", &buff);
	int n = strlen(buff);

	string N, D;

	N = D = "";

	int pt = -1;

	for(int i = 0;i < n;i++) {
		if(buff[i] == '.') pt = i;
		else {
			if(pt == -1) N.push_back(buff[i]);
			else D.push_back(buff[i]);
		}
	} 

	while(!D.empty() && D.back() == '0') D.pop_back();

	if(N.empty()) N = "0";
	
	reverse(ALL(N));
	while((int)N.size() > 1 && N.back() == '0') N.pop_back();
	reverse(ALL(N));

	//cout << N << " " << D << "\n";

	if(D.empty()) {
		if((int)N.size() == 1) {
			cout << N << '\n';
			return true;
		}else {
			int T = (int)N.size();
			cout << N[0];
			while(N.back() == '0') N.pop_back();
			if((int)N.size() > 1) cout << '.';
			for(int i = 1;i < (int)N.size();i++) cout << N[i];
			cout << "E" << T - 1 << '\n';
		}
	}else {
		if((int)N.size() == 1 && N[0] == '0') {
			int f = -1;
			for(int i = 0;i < (int)D.size();i++) {
				if(D[i] != '0') {
					f = i;
					break;
				}
			}
			cout << D[f];
			if(f + 1 < (int)D.size()) {
				cout << '.';
				for(int i = f + 1;i < (int)D.size();i++) cout << D[i];
			}
			cout << "E-" << f + 1 << '\n';
		}else {
			if((int)N.size() == 1) cout << N << "." << D << '\n';
			else {
				cout << N[0] << ".";
				for(int i = 1;i < (int)N.size();i++) cout << N[i];
				cout << D << "E" << (int)N.size() - 1 << '\n';
			}
		}
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}