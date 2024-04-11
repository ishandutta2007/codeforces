#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int ask_a(int x) {
	cout << "A " << x << endl;
	int res;
	cin >> res;
	return res;
}

int ask_b(int x) {
	cout << "B " << x << endl;
	int res;
	cin >> res;
	return res;
}

void ask_c(int x) {
	cout << "C " << x << endl;
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<char> is_prime(n + 1, 1);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++)
		if (is_prime[i])
			for (int j = i * 2; j <= n; j += i)
				is_prime[j] = 0;

	vector<int> primes;
	for (int i = 0; i <= n; i++)
		if (is_prime[i])
			primes.push_back(i);

	debug(primes);
	int number_primes = (int) primes.size();
	const int block = (int) ceil(sqrt(number_primes));
	debug(block);
	int block_number = -1;
	vector<int> prime_divs;
	vector<char> is_deleted(n + 1, 0);
	auto sum = [&](int start, bool delete_mod) {
		int sum = 0;
		for (int i = start; i <= n; i += start) {
			sum += 1 - is_deleted[i];
			if (delete_mod)
				is_deleted[i] = 1;
		}
		debug(start, sum);
		return sum;
	};
	for (int i = 0; i < number_primes; i++) {
		debug(0 + is_deleted[5]);
		int p = primes[i];
		int must_be = sum(p, true);
		if (ask_b(p) != must_be)
			prime_divs.push_back(p);
		if ((i + 1) % block == 0 || i == number_primes - 1) {
			must_be = sum(1, false);
			if (block_number == -1 && must_be != ask_a(1))
				block_number = i / block;
		}
	}
	debug(block_number);

	if (block_number == -1)
		ask_c(1);
	for (int i = block_number * block; i < (block_number + 1) * block; i++) {
		int p = primes[i];
		int must_be = sum(p, false);
		if (must_be != ask_a(p)) {
			debug(p);
			prime_divs.push_back(p);
			break;
		}
	}
	int x = 1;
	for (auto p : prime_divs) {
		long long now = 1ll * p * p;
		while (true) {
			if (now > n) {
				debug(now);
				x *= now / p;
				break;
			}
			int must_be = sum(now, false);
			if (must_be != ask_a(now))
				now *= p;
			else {
				debug(now);
				x *= now / p;
				break;
			}
		}
	}
	ask_c(x);
}