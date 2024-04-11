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

bool mark[20][20],dp[20][20];
int t,n;
int a[20];
LL val[20];

inline bool go (int pos, int carry){
	if (pos == n){
		if (carry == 0)
			return true;
		return false;
	}
	if (mark[pos][carry])
		return dp[pos][carry];
	mark[pos][carry] = true;
	for (int i=0; i<=6; i++)
		for (int j=0; j+i<=6; j++) if ((carry + i*4 + j*7) % 10 == a[pos]){
			if (go(pos+1, (carry + i*4 + j*7)/10))
				return dp[pos][carry] = true;
		}
	return dp[pos][carry] = false;
}

inline void print(int pos, int carry, LL p){
	if (pos == n){
		for (int i=0; i<6; i++)
			cout << val[i] << ' ';
		cout << endl;
		return;
	}
	for (int i=0; i<=6; i++)
		for (int j=0; j+i<=6; j++) if ((carry + i*4 + j*7) % 10 == a[pos]){
			if (go(pos+1, (carry + i*4 + j*7)/10)){
				for (int k=0; k<6; k++){
					if (k<i)
						val[k] = val[k] + p * 4;
					else if (k<i+j)
						val[k] = val[k] + p * 7;
				}
				print(pos+1, (carry + i*4 + j*7)/10, p * 10LL);
				return;
			}
		}
}

int main(){
	cin >> t;
	for (int o=0; o<t; o++){
		string s; cin >> s;
		n = (int)s.size();
		for (int i=0; i<(int)s.size(); i++)
			a[n-i-1] = s[i]-'0';
		memset(mark, false, sizeof mark);
		if (go(0, 0)){
			memset(val, 0, sizeof val);
			print(0, 0, 1);
		}else
			cout << -1 << endl;
	}
	return 0;
}