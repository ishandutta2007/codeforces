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

const int inf = 1000000000;

int n;
int cnt[10];

inline int go (vector <int> A, vector <int> B){
	int ret = 0;
	int poi = 0;
	for (int i=0; i<(int)A.size(); i++){
		if (A[i]==0)
			continue;
		if (A[i] <= B[poi]){
			B[poi]-= A[i];
			ret+= abs(i-poi) * A[i];
		}else{
			A[i]-= B[poi];
			ret+= abs(i-poi) * B[poi];
			poi++;
			i--;
		}
	}
	return ret/2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int sum = 0;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		cnt[temp]++;
		sum+= temp;
	}
	int ret = inf;
	for (int i=0; i<=sum/4; i++) if ((sum-i*4)%3 == 0 && i+(sum-i*4)/3 <= n){
		vector <int> Q1; for (int j=0; j<=4; j++) Q1.push_back(cnt[j]);
		vector <int> Q2; Q2.push_back(n-i-(sum-i*4)/3); Q2.push_back(0); Q2.push_back(0); Q2.push_back((sum-i*4)/3); Q2.push_back(i);
		ret = min(ret, go(Q1, Q2));
	}
	if (ret == inf)
		cout << -1 << endl;
	else
		cout << ret << endl;
	return 0;
}