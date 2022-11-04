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
typedef pair<int,int> pii;
typedef complex<double> point;

int n,m;
int t[5005],l[5005],r[5005],d[5005];
int func[5005],maxi[5005];

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++)
		maxi[i] = 1000000000;
	for (int i=0; i<m; i++){
		cin >> t[i] >> l[i] >> r[i] >> d[i];
		l[i]--; r[i]--;
		if (t[i] == 1){
			for (int j=l[i]; j<=r[i]; j++)
				func[j]+= d[i];
		}else{
			for (int j=l[i]; j<=r[i]; j++)
				maxi[j] = min(maxi[j], d[i] - func[j]);
		}
	}
	memset(func, 0, sizeof func);
	for (int i=0; i<m; i++){
		if (t[i] == 1){
			for (int j=l[i]; j<=r[i]; j++)
				func[j]+= d[i];
		}else{
			bool flag = false;
			for (int j=l[i]; j<=r[i]; j++) if ((func[j] + maxi[j]) == d[i])
				flag = true;
			if (!flag){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++)
		cout << maxi[i] << ' ';
	cout << endl;
	return 0;
}