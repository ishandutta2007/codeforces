#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>

using namespace std;

int N, M;
bool fat;

int main()
{
	//	freopen ("cf510a.in", "r", stdin);
	//	freopen ("cf510a.out", "w", stdout);
	scanf("%d %d", &N, &M);
	for (int l = 0; l < N; l++)
	{
		if (!(l % 2))
		{
			for (int i = 0; i < M; i++)
			{
				printf("#");
			}
			printf("\n");
		}
		else
		{
			if (!fat)
			{
				fat = true;
				for (int j = 1; j < M; j++)
				{
					printf(".");
				}
				printf("#\n");
			}
			else
			{
				printf("#");
				for (int j = 1; j < M; j++)
				{
					printf(".");
				}
				printf("\n");
				fat = false;
			}
		}
	}
}