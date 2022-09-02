#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

void Do(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1; y = 0;
	}
	else {
		int dx, dy;
		Do(b, a%b, dx, dy);
		x = dy; y = dx - a / b * dy;
	}
}

int main() {
	int N; scanf("%d", &N);
	map <int, int> Mx;
	int tn = N;
	for(int i=2;i*i<=tn;i++) while(tn % i == 0) Mx[i]++, tn /= i;
	if(tn > 1) Mx[tn]++;
	if(szz(Mx) == 1) {
		puts("NO");
		return 0;
	}
	vector <pii> vx;
	for(pii e : Mx) vx.pb(e);
	int p = vx[0].Fi, q = vx[1].Fi;
	int x, y;
	Do(p, q, x, y);
	x = -x, y = -y;
	if(x < 0) x += N / p;
	else y += N / q;
	while(x < 0) x += q, y -= p;
	while(y < 0) x -= q, y += p;
	puts("YES\n2");
	printf("%d %d\n", x, N / p);
	printf("%d %d\n", y, N / q);
	return 0;
}