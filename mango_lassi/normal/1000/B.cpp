#include <iostream>
using namespace std;

const int N = 1e5;
long long place[N + 2];
long long after[N + 2];

int main() {
	int n, m;
	cin >> n >> m;
	
	place[0] = 0;
	place[n+1] = m;
	for (int i = 1; i <= n; ++i) {
		cin >> place[i];
	}
	
	long long on_time = 0;
	bool is_on = (n % 2 == 0 ? true : false);

	after[n+1] = 0;
	for (int i = n; i >= 0; --i) {
		if (is_on) on_time += place[i+1] - place[i];
		after[i] = on_time;
		is_on ^= 1;
	}
	
	// for (int i = 0; i <= n+1; ++i) std::cout << after[i] << ' '; std::cout << '\n';
	
	is_on = false;
	on_time = 0;
	long long res = 0;
	for (int i = 0; i <= n+1; ++i) {
		if (is_on) on_time += place[i] - place[i-1];
		is_on ^= 1;

		// std::cout << i <<' ' << place[i] << ' ' << place[i-1] << ' ' << on_time << ' ' << after[i] << ' ' << (m - place[i]) - after[i] - 1 << '\n';

		res = std::max(res, on_time + after[i]);
		if ((place[i+1] != place[i] + 1) && (!is_on)) {
			res = std::max(res, on_time + (m - place[i]) - after[i] - 1);
		}
	}
	std::cout << res << '\n';
}