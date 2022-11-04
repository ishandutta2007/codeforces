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

int n,m,k;
vector <pii> Q;

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		Q.push_back(pii(temp,0));
	}
	for (int i=0; i<m; i++){
		int temp; cin >> temp;
		Q.push_back(pii(temp,1));
	}
	sort(Q.begin(), Q.end());
	int balance = 0;
	for (int i=(int)Q.size()-1; i>=0; i--){
		if (Q[i].second == 0)
			balance--;
		else
			balance++;
		if (balance < 0){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}