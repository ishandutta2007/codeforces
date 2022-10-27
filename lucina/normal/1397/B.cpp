#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <functional>
//rating
const int MAXN = 100005;
long long numbers[MAXN];
long long max_xx = 5000000005;
long long max_xx2 = 10000000005;
int main(int argc, char* argv[])
{
	int t;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
	int n;
	//scanf("%d", &t);
	//while (t--) 
	{
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			scanf(" %lld", &numbers[i]);
		}
		std::sort(numbers, numbers + n);
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += (numbers[i] - 1);
		}
		if (n == 3) {
			for (long long i = 2; i * i <= max_xx; i++) {
				long long tmp_res = 0;
				long long num_now = 1;
				int j;
				for (j = 0; j < n; j++) {
					tmp_res += std::abs(numbers[j] - num_now);
					if (tmp_res > res) {
						break;
					}
					num_now *= i;

				}
				if (j == n && tmp_res < res) {
					res = tmp_res;
				}
			}
		}
		else {
			for (long long i = 2; i * i * i<= max_xx2; i++) {
				long long tmp_res = 0;
				long long num_now = 1;
				int j;
				for (j = 0; j < n; j++) {
					tmp_res += std::abs(numbers[j] - num_now);
					if (tmp_res > res) {
						break;
					}
					num_now *= i;

				}
				if (j == n && tmp_res < res) {
					res = tmp_res;
				}
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}