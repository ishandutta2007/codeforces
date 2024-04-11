#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
// #define i128 __int128_t

typedef unsigned int uint;
typedef unsigned long long int uint64;
inline uint xrand(void) {
	static uint x = 123456789;
	static uint y = 362436069;
	static uint z = 521288629;
	static uint w = 88675123;
	uint t;
	t = x ^ (x << 11); x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
inline uint randrange(uint n) {
	return (uint64(xrand()) * n) >> 32;
}


int ace[505555],row,col;
int ancestor(int x) { return x - ace[x] ? ace[x] = ancestor(ace[x]) : x; }

void merge(int x, int y) {
	if (randrange(2))swap(x, y);
	ace[ancestor(x)] = ancestor(y);
}
int main() {
	int q;
	scanf("%d%d%d", &row, &col, &q);
	for (int i = 1; i <= row + col; i++)
		ace[i] = i;
	while (q--) {
		int x,y;
		scanf("%d%d", &x, &y);
		merge(x, y + row);
	}
	int res = -1;
	for (int i = 1; i <= row + col; i++) {
		if (ancestor(i) == i)res++;
	}
	printf("%d\n", res);
	return 0;
}