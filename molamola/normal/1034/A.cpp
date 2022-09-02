#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int N, A[300030], X[300030];

int gc(int x, int y) { return y?gc(y, x%y):x;}
int P[15000050];
int pp[15000050];

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A+i);
	sort(A+1, A+1+N);
	int g = A[1];
	for(int i=2;i<=N;i++) g = gc(g, A[i]);
	for(int i=1;i<=N;i++) A[i] /= g;
	for(int i=1;i<=N;i++) P[A[i]]++;
	const int MX = 15000000;
	for(int i=2;i<=MX;i++) {
		if(pp[i] == 0) {
			for(int j=i+i;j<=MX;j+=i) {
				pp[j] = 1;
			}
		}
	}
	int mx = 0;
	for(int i=2;i<=MX;i++) if(pp[i] == 0) {
		int c = 0;
		for(int j=i;j<=MX;j+=i) c += P[j];
		mx = max(mx, c);
	}
	if(mx == 0) puts("-1");
	else printf("%d\n", N - mx);
	return 0;
}