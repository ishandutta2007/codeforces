#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = 200500;
int t[N], d[N];
int qu[N];
long long answer[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, b;
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &t[i], &d[i]);
	
	long long curT = 0;
	int ptr = 0;
	int qul = 0, qur = 0;

	while (true)
	{
		if (qul == qur && ptr == n) break;

		if (qul == qur || (ptr != n && curT + d[qu[qul] ] > t[ptr] ) )
		{
			if (qul == qur) curT = t[ptr];
			qu[qur++] = ptr;
			if (qur - qul > b + 1)
			{
				qur--;
				answer[qu[qur] ] = -1;
			}
			ptr++;
			continue;
		}
		curT += d[qu[qul] ];
		answer[qu[qul] ] = curT;
		qul++;
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", answer[i] );
	printf("\n");

	return 0;
}