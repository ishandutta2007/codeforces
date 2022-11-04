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

const int MAXW = 1<<21;

int n,k;
int cnt[MAXW];

int main(){
	scanf("%d%d", &n, &k);
	int maxi = 0;
	for (int i=0; i<n; i++){
		int temp; 
		scanf("%d", &temp);
		cnt[temp]++;
		maxi = max(maxi, temp);
	}
	for (int i=1; i<MAXW; i++)
		cnt[i]+= cnt[i-1];
	int res = 1;
	for (int i=maxi; i>1; i--){
		int len = min(i-1, k);
		int Count = 0;
		for (int j=i; j<=maxi; j+=i)
			Count+= cnt[j+len] - cnt[j-1];
		if (Count == n){
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}