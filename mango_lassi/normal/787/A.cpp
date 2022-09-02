#include <iostream>
#include <utility>

std::pair<std::pair<int, int>, int> gcd(int a, int b) {
	if (b == 0) {
		return std::make_pair(std::make_pair(1, 0), a);
	} else {
		int c = a % b;
		int mult = (a - c) / b;
		std::pair<std::pair<int, int>, int> res = gcd(b, c);
		return std::make_pair(std::make_pair(res.first.second, res.first.first - res.first.second * mult), res.second);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b, c, d;
	std::cin >> b >> a >> d >> c;
	if (d > b) {
		int temp = d;
		d = b;
		b = temp;
		temp = a;
		a = c;
		c = temp;
	}
	std::pair<std::pair<int, int>, int> res = gcd(b, d);
	int div = res.second;
	int bm = res.first.first;
	int dm = res.first.second;
	// b bm + d dm = div
	// bx - dy = c - a
	// x = bm * (c - a) / div
	// y = -dm * (c- a) / div
	// a + bx = c + dy
	if ((c - a) % div) {
		std::cout << "-1\n";
	} else {
		int x = bm * (c - a) / div;
		int y = -dm * (c - a) / div;
		// bx - dy = c - a
		// a + bx = c + dy
		while((x > 0) && (y > 0)) {
			x -= d / div;
			y -= b / div;
		}
		while((x < 0) || (y < 0)) {
			x += d / div;
			y += b / div;
		}
		std::cout << a + b * x << '\n';
	}
}