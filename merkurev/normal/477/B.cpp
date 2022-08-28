#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);

	vector <vector <int> > V;
	int minOdd = 1;
	for (int i = 0; i < n; i++)
	{
		vector <int> v;
		if (minOdd % 3 != 0)
			v.push_back(minOdd + 3);
		else
			v.push_back(minOdd + 1);
		v.push_back(minOdd);
		v.push_back(minOdd + 2);
		v.push_back(minOdd + 4);
		minOdd += 6;
		V.push_back(v);
	}
	int mx = minOdd - 2;
	printf("%d\n", mx * k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d ", V[i][j] * k);
		printf("\n");
	}
	

	return 0;
}