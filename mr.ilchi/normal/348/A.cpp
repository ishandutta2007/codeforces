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
int a[1<<20];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	LL lo=0,hi=(1LL<<40),ans=0;
	while (lo<=hi){
		LL mid = (lo + hi) / 2;
		LL sum = 0;
		for (int i=0; i<n; i++){
			if (a[i]>mid){
				sum=-1LL;
				break;
			}else
				sum+= mid-a[i];
		}
		if (sum>=mid){
			ans=mid; hi=mid-1;
		}else
			lo=mid+1;
	}
	cout << ans << endl;
	return 0;
}