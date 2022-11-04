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
int p[1<<21];

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		p[i] = i;
	for (int i=2; i<=n; i++)
		for (int j=(i-1)+n-n%i; j>(i-2); j-=i)
			swap(p[j], p[min(n+i-1,j+i)]);
	for (int i=n; i<=2*n-1; i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}