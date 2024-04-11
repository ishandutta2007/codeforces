//no print start
#pragma region Header
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <complex>
#include <bitset>
#include <random>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll, lint;
typedef long double ldouble;

#define sz(v) ((int) (v).size())
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define For(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()

#ifdef ALEX
#define eprintf(...) fprintf(stdout, __VA_ARGS__)
#define print_var(x) cout << #x << " = " << x << endl
#define print_array(arr, len) {cout << #arr << " = "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_iterable(it) {cout << #it << " = "; for(const auto& e : it) cout << e << ' '; cout << endl << endl;}
#define print_2d_array(arr, len1, len2) {\
		cout << #arr << ':' << endl;\
		for(int i = 0; i < len1; ++i, cout << endl) \
			for(int j = 0; j < len2; ++j)\
				cout << arr[i][j] << ' '; \
		cout << endl;\
	}
#define print_endl() cout << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0;
#define print_iterable(it) (void)0;
#define print_2d_array(arr, len1, len2) (void)0;
#define print_endl() (void)0
#endif

#define forn(var, count) for (int var = 0; var < count; var++)

template<class T>
string to_string(T arr, int len = 1e9) {
	stringstream ss;
	int i = 0;
	for (auto item : arr) {
		ss << item << ' ';
		if (++i == len)
			break;
	}
	return ss.str();
}

#ifdef ALEX
#define dbg(expr) cout << "[line " << __LINE__ << "] " << (#expr) << ": " << (expr) << endl;
#else
#define dbg(expr) (void) 0;
#endif

#pragma endregion
//no print end

vector<int> get_answer(const vector<int> & arr, int k) {
	int n = arr.size();
	vector<int> result(n);
	For(i, n) {
		if (i == 0) {
			result[0] = min(k + 1, n);
			continue;
		}
		if (arr[i] == 0) {
			result[i] = min(i + k, n - 1) - max(i - k, 0) + 1;
			continue;
		}
		int prev_index = arr[i] - 1;
		int prv = result[prev_index];
		int cur_r = min(i + k, n - 1);
		int cur_l = max(i - k, 0);
		int cur = cur_r - cur_l + 1;
		int prev_r = min(prev_index + k, n - 1);
		int prev_l = max(prev_index - k, 0);
		int inter_l = max(prev_l, cur_l);
		int inter_r = min(prev_r, cur_r);
		int inter_size = max(0, inter_r - inter_l + 1);
		result[i] = prv + cur - inter_size;
	}
	return result;
}

vector<int> get_correct(const vector<int> & arr, int k) {
	int n = arr.size();
	vector<int> answer(n);
	For(i, n) {
		set<int> kek;
		int x = i;
		while (x >= 0) {
			for (int i = max(0, x - k); i <= min(x + k, n - 1); i++)
				kek.insert(i);
			x = arr[x] - 1;
		}
		answer[i] = kek.size();
	}
	return answer;
}

void stress() {
	for (int t = 0; ; t++) {
		int n = 1000;
		int k = rand() % (n + 1);
		vector<int> arr(n);
		For(i, n)
			arr[i] = rand() % (i + 1);
		auto prog = get_answer(arr, k);
		auto corr = get_correct(arr, k);
		if (prog != corr) {
			printf("%d %d\n", n, k);
			for (auto v : arr)
				printf("%d ", v);
			printf("\n");
			print_array(prog, n);
			print_array(corr, n);
			break;
		}
		cerr << "passed " << t << '\r';
	}
	exit(0);
}

void solve() {
#ifdef ALEX
	//stress();
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	auto answer = get_answer(arr, k);
	For(i, n) {
		printf("%d", answer[i]);
		if (i != n - 1)
			printf(" ");
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
#ifdef ALEX
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}