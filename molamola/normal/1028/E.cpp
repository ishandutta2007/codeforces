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

int N;
ll B[150050];
ll A[150050];

int main() {
	scanf("%d", &N);
	rep(i, N) scanf("%lld", B + i);
	if(*min_element(B, B+N) == *max_element(B, B+N)) {
		if(B[0] == 0) {
			puts("YES");
			rep(i, N) printf("1 "); puts("");
		}
		else {
			puts("NO");
		}
	}
	else {
		ll v = *max_element(B, B+N);
		int f = -1;
		rep(i, N) {
			if(B[i] == v && B[(i+N-1)%N] != v) {
				f = i; break;
			}
		}
		A[f] = B[f];
		int o = 0;
		for(int i=(f+N-1)%N;i!=f;i=(i+N-1)%N) {
			ll temp = B[i];
			if(temp > 0) A[i] = A[(i+1)%N] + temp;
			else {
				if(o == 0) A[i] = A[(i+1)%N] * 2, o = 1;
				else A[i] = A[(i+1)%N];
			}
		}
		/*
		 ll sum = 0;
		 rep(i, N) {
			if(i == (f + N - 1) % N) sum -= B[i];
			else sum += B[i];
		 }
		 sum %= B[f];
		 if(sum == 0) sum += B[f];
		 A[f] = B[f];
		 A[(f+1)%N] = B[f] + sum;
		 for(int a=(f+2)%N;a!=f;a=(a+1)%N) {
			A[a] = A[(a+N-1)%N] + B[(a+N-1)%N];
		 }*/
		puts("YES");
		rep(i, N) printf("%lld ", A[i]); puts("");
	}
	return 0;
}