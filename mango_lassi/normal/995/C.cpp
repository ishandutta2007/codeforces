#include <iostream>
#include <vector>

const long long N = 1e5;
const long long M = 1e6;
const long long MM = M + M / 2;
int sign[N];
int group[N];
long long group_dx[N];
long long group_dy[N];

bool isShort(long long a, long long b) {
	return a * a + b * b <= M * M;
}
bool isPrettyShort(long long a, long long b) {
	return a * a + b * b <= MM * MM;
}

std::vector<int> active;

int collapse(int i) {
	if (group[i] != i) {
		sign[i] *= collapse(group[i]);
		group[i] = i;
	}
	return sign[i];
}

void add(int i) {
	int dx = group_dx[i];
	int dy = group_dy[i];
	for (int j = 0; j < active.size(); ++j) {
		int t = active[j];
		int gx = group_dx[t];
		int gy = group_dy[t];
		for (int s = -1; s <= 1; s += 2) {
			dx *= s;
			dy *= s;
			if (isShort(gx + dx, gy + dy)) {
				group[i] = t;
				sign[i] = s;
				group_dx[t] += dx;
				group_dy[t] += dy;

				active[j] = active.back();
				active.pop_back();
				add(t);
				return;
			}
			dx *= s;
			dy *= s;
		}
	}
	active.push_back(i);
}


int main() {
	long long n;
	std::cin >> n;
	for (long long i = 0; i < n; ++i) {
		int dx, dy;
		std::cin >> dx >> dy;
		sign[i] = 1;
		group[i] = i;
		group_dx[i] = dx;
		group_dy[i] = dy;
		add(i);
	}

	int c = active.size();
	int high = 1<<c;
	for (int bits = 0; bits < high; ++bits) {
		long long sum_x = 0;
		long long sum_y = 0;
		for (int j = 0; j < c; ++j) {
			int s = (bits & (1<<j)) ? 1 : -1;
			sign[active[j]] = s;
			sum_x += s * group_dx[j];
			sum_y += s * group_dy[j];
		}
		if (isPrettyShort(sum_x, sum_y)) break;
	}
	for (int i = 0; i < n; ++i) std::cout << collapse(i) << ' '; std::cout << '\n';
}