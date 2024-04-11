#include <iostream>
#include <string>

const int N = 1e3;
const long long MOD = 1e9 + 7;
long long ways[N+1];
int min_dist[N+1];
int count[26];

int ind(char c) {
	return (int)(c) - (int)('a');
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	for (int i = 0; i < 26; ++i) {
		std::cin >> count[i];
	}
	ways[0]= 1;
	min_dist[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ways[i] = 0;
		min_dist[i] = 2 * N;
	}
	int max_dist = 0;
	for (int s = 0; s < n; ++s) {
		int max = N*N;
		int dist = 1;
		for (int e = s; e < n; ++e, ++dist) {
			max = min(max, count[ind(str[e])]);
			if (dist > max) {
				break;
			} else {
				min_dist[e+1] = min(min_dist[e+1], min_dist[s] + 1);
				ways[e+1] = (ways[e+1] + ways[s]) % MOD;
				if (dist > max_dist) {
					max_dist = dist;
				}
			}
		}
	}
	std::cout << ways[n] << "\n" << max_dist << "\n" << min_dist[n] << "\n";
}