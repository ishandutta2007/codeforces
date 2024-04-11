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

const int maxN = 100 * 1000 + 10;

bool mark[maxN];
char ord [maxN];
int n,m;
int a[maxN],to[maxN],out[maxN];

int main(){
	
	cin >> n >> m;

	int pl = 0 , mi = 0;
	for (int i=1; i<=n; i++){
//		string s; cin >> s;
//		ord[i] = s[0];
//		s = s.substr(1);
//		a[i] = atoi(s.c_str());
		cin >> ord[i] >> a[i];
//		cout << ord[i] << ' ' << a[i] << endl;
		if (ord[i]=='+'){
			pl++;
			to[a[i]]++;
		}
		if (ord[i]=='-'){
			mi++;
			out[a[i]]++;
		}
	}

	int cnt = 0;

	for (int i=1; i<=n; i++){
		int tmp = to[i] + mi - out[i];
		if (tmp == m){
			mark[i] = true;
	//		cout << i << ' ' << to[a[i]] << ' ' << i << ' ' << out[a[i]] << endl;
			cnt++;
		}
	}

	for (int i=1; i<=n; i++){
		
		if (ord[i]=='+'){
			if (!mark[a[i]]){
				cout << "Lie" << endl;
			}
			else{
				if (cnt==1)
					cout << "Truth" << endl;
				else
					cout << "Not defined" << endl;
			}
		}
		else{
			if (!mark[a[i]]){
				cout << "Truth" << endl;
			}
			else{
				if (cnt==1)
					cout << "Lie" << endl;
				else
					cout << "Not defined" << endl;
			}
		}
	}

	return 0;
}