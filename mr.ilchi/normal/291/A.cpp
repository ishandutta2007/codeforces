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
vector <int> Q;

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		if (temp!=0) Q.push_back(temp);
	}
	sort(Q.begin(), Q.end());
	int ans = 0;
	for (int i=0; i<(int)Q.size(); i++){
		int j=i;
		while (j<(int)Q.size() && Q[i]==Q[j]) j++;
		if (j-i > 2){
			cout << -1 << endl;
			return 0;
		}
		ans+= (j-i == 2);
		i=j-1;
	}
	cout << ans << endl;
	return 0;
}