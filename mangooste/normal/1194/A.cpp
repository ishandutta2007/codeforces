//#define _CRT_SECURE_NO_WARNINGS

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define all(v) begin(v), end(v)
#define FIXED cout << fixed << setprecision(10)
#define endL '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

template <typename T>

istream & operator >> (istream & in, vector <T> &vec) {
	ll n;
	in >> n;
	vec.resize(n);
	for (auto &u : vec) {
		in >> u;
	}
	return in;
}

template <typename T>

ostream & operator << (ostream & out, vector <T> &vec) {
	for (auto &u : vec) {
		out << u << ' ';
	}
	out << '\n';
	return out;
}

template <typename T>

ostream & operator << (ostream & out, vector <vector <T>> &vec) {
	for (auto &u : vec) {
		out << u;
	}
	out << '\n';
	return out;
}

signed main()
{
	FAST;
	FIXED;
	ll q;
	cin >> q;
	while (q--) {
		ll n, x;
		cin >> n >> x;
		cout << x * 2 << '\n';
	}
	//system("pause");
}