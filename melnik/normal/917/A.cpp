#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 5050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];
// int pref_sum[maxn];
int pref_sum2[maxn];

int Solve() {
	int n = strlen(t);
	int ans = 0;
	for (int l = 0; l < n; ++l) {
		int open_brackets = 0;
		int close_brackets = 0;
		int bal = 0;
		for (int r = l; r < n; ++r) {
			if (t[r] == '(')
				++bal;
			if (t[r] == ')')
				--bal;
			if (t[r] == '?') {
				++close_brackets;
				--bal;
			}
			while (bal < 0 && close_brackets) {
				--close_brackets;
				++open_brackets;
				bal += 2;
			}
			if (bal < 0)
				break;
			if (bal == 0)
				++ans;
		}
	}
	return ans;
}

// int Solve() {
// 	int n = strlen(t);
// 	// for (int i = 0; i < n; ++i) {
// 	// 	int prev = i ? pref_sum[i - 1] : 0;
// 	// 	if (t[i] == '(')
// 	// 		pref_sum[i] = prev + 1;
// 	// 	if (t[i] == ')')
// 	// 		pref_sum[i] = prev - 1;
// 	// 	if (t[i] == '?')
// 	// 		pref_sum[i] = prev;
// 	// }
// 	for (int i = 0; i < n; ++i) {
// 		int prev = i ? pref_sum2[i - 1] : 0;
// 		if (t[i] == '?')
// 			pref_sum2[i] = prev + 1;
// 		else
// 			pref_sum2[i] = prev;
// 	}
// 	int ans = 0;
// 	for (int l = 0; l < n; ++l) {
// 		int bal = 0;
// 		// int worst_bal = 0;
// 		// int worst_prefix = -1;
// 		for (int r = l; r < n; ++r) {
// 			if (t[r] == '(')
// 				++bal;
// 			if (t[r] == ')')
// 				--bal;
// 			int questions_cnt = pref_sum2[r] - (l ? pref_sum2[l - 1] : 0);
// 			if (bal + questions_cnt < 0)
// 				break;
// 			if (!((bal + questions_cnt) & 1) && bal - questions_cnt <= 0 && t[r] != '(')
// 				++ans;
// 			// if (t[i] == '(') {
// 			// 	++bal;
// 			// 	if (bal < worst_bal) {
// 			// 		worst_bal = bal;
// 			// 		worst_prefix = r;
// 			// 	}
// 			// }
// 			// if (t[i] == ')') {
// 			// 	--bal;
// 			// 	if (bal < worst_bal) {
// 			// 		worst_bal = bal;
// 			// 		worst_prefix = r;
// 			// 	}
// 			// }

// 			// int questions_cnt = pref_sum2[r] - (l ? pref_sum2[l - 1] : 0);
// 			// int cur_bal = bal;
// 			// if (worst_prefix != -1) {
// 			// 	int pref_q_cnt = pref_sum2[worst_prefix] - (l ? pref_sum2[l - 1] : 0);
// 			// 	if ()
// 			// }
// 		}
// 	}
// 	// printf("%d\n", ans);
// 	return ans;
// }

char t2[maxn];

int Brute() {
	int n = strlen(t);
	for (int i = 0; i < n; ++i) {
		int prev = i ? pref_sum2[i - 1] : 0;
		if (t[i] == '?')
			pref_sum2[i] = prev + 1;
		else
			pref_sum2[i] = prev;
	}
	int ans = 0;
	for (int l = 0; l < n; ++l) {
		int bal = 0;
		for (int r = l; r < n; ++r) {
			if (t[r] == '(')
				++bal;
			if (t[r] == ')')
				--bal;
			int questions_cnt = pref_sum2[r] - (l ? pref_sum2[l - 1] : 0);
			if (bal + questions_cnt < 0 || ((bal + questions_cnt) & 1))
				continue;
			int open_brackets = 0;
			while (open_brackets <= questions_cnt) {
				if (bal + open_brackets - (questions_cnt - open_brackets) == 0)
					break;
				++open_brackets;
			}
			if (open_brackets > questions_cnt)
				continue;
			for (int i = l; i <= r; ++i) {
				if (t[i] == '(' || t[i] == ')') {
					t2[i] = t[i];
					continue;
				}
				if (open_brackets) {
					t2[i] = '(';
					--open_brackets;
				} else
					t2[i] = ')';
			}

			int cur_bal = 0;
			for (int i = l; i <= r; ++i) {
				if (t2[i] == '(')
					++cur_bal;
				if (t2[i] == ')')
					--cur_bal;
				if (cur_bal < 0)
					break;
			}
			if (!cur_bal)
				++ans;
		}
	}
	return ans;
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    gets(t);
    cout << Solve();

    // int it = 100000;
    // while (it--) {
    // 	int n = 1 + rand() % 4;
    // 	for (int i = 0; i < n; ++i) {
    // 		int x = rand() % 3;
    // 		if (x == 0)
    // 			t[i] = '(';
    // 		if (x == 1)
    // 			t[i] = '?';
    // 		if (x == 2)
    // 			t[i] = ')';
    // 	}
    // 	t[n] = '\0';
    // 	if (Solve() != Brute()) {
    // 		puts("kek");
    // 		cout << t << endl;
    //         cout << Solve() << ' ' << Brute() << endl;
    //         return 0;
    // 	}
    // }
    return 0;
}