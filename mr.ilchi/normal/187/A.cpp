/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 200 * 1000 + 10;

int n;
int a[maxN],b[maxN],pos[maxN];

int main(){
	
	scanf("%d" , &n);

	for (int i=1; i<=n; i++) { scanf ("%d" , &a[i]); }
	for (int i=1; i<=n; i++) { scanf ("%d" , &b[i]); pos[b[i]] = i; }

	if (n==1){
		printf("0\n");
		return 0;
	}

	int ans = 0;

	for (int i=2; i<=n; i++) if (pos[a[i]]<pos[a[i-1]]){
		ans = n-i+1;
		break;
	}

	printf ("%d\n" , ans);

	return 0;
}