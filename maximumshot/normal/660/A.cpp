#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int N = 1000000;

int gcd(int x, int y) {
	return (x == 0?y : gcd(y % x, x));
}

bool solve() {

	vec< char > prime(N, 1);
	
	prime[0] = prime[1] = 0;

	for(int i = 2;i * i < N;i++) {
		if(!prime[i]) continue;
		for(int j = i * i;j < N;j += i) prime[j] = 0;
	}

	vec< int > pr;

	for(int i = 2;i < N;i++) {
		if(prime[i]) pr.push_back(i);
	}

	int n, x, y;
	scanf("%d %d", &n, &x);

	vec< int > way;
	int res = 0;

	way.push_back(x);

	for(int i = 2;i <= n;i++) {
		scanf("%d", &y);
		if(gcd(x, y) > 1) {
			res++;
			for(int j = 0;j < (int)pr.size();j++) {
				int val = pr[j];
				if(gcd(x, val) == 1 && gcd(val, y) == 1) {
					way.push_back(val);
					break;
				}
			}
		}
		way.push_back(y);
		x = y;
	}

	printf("%d\n", res);

	for(auto i : way) printf("%d ", i); 
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}