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

int n;
int ans[1<<20];

void go (vector <int> Q){
	if (Q.empty())
		return;
	if (Q.size()==1){
		cout << Q[0] << ' ';
		return;
	}
	int hi = (int)Q.size()-1;
	int p = 0;
	while ((1<<p)-1 < hi) p++;
	if ((1<<p)-1 > hi){
		p--;
		for (int j=(1<<p); j<(int)Q.size(); j++)
			swap(Q[j],Q[j-(1<<p)]);
	}
	for (int i=0; i<(1<<p); i++)
		cout << Q[i ^ ((1<<p)-1)] << ' ';
	vector <int> QQ;
	for (int i=(1<<p); i<(int)Q.size(); i++)
		QQ.push_back(Q[i]);
	go(QQ);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << ((LL)n * (n+1)) << endl;
	vector <int> Q;
	for (int i=0; i<=n; i++)
		Q.push_back(i);
	go(Q);
	cout << endl;
	return 0;
}