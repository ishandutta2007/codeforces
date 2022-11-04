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

int n;
int a[1000];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int cur = 0;
	while (true){
		if (a[cur] == 0){
			if (cur+1 == n)
				break;
			cout << 'R';
			cur++;
			continue;
		}
		cout << 'P';
		a[cur]--;
		if (cur == 0)
			cout << "RL";
		else
			cout << "LR";
	}
	cout << endl;
	return 0;
}