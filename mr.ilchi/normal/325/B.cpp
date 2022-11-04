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

LL n;

LL mul (LL A, LL B) { return (n+1)/B>=A ? A*B : (n+1); }
LL add (LL A, LL B) { return min(n+1, A+B); }

int main(){
	cin >> n;
	vector <LL> ans;
	for (LL p=1; p<=n+1; p<<=1){
		LL s = 1, e = 2000000000LL;
		while (s<=e){
			LL mid = (s + e) / 2;
			LL temp = mid * (mid-1) / 2;
			temp = add(temp, mul(p-1, mid));
			if (temp > n){
				e = mid-1;
			}else if (temp < n){
				s = mid+1;
			}else{
				if (mid%2 == 1)
					ans.push_back(mid * p);
				break;
			}
		}
	}
	if (ans.empty()){
		cout << -1 << endl;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}