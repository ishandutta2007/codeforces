#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 1011116

// hash.cpp @ fstqwq/CodeForcesTemplate
const int HA = 2;
const int PP[] = {318255569, 259906247, 66604919, 19260817},
	 	  QQ[] = {1010451419, 1011111133, 1021111159, 1033111117};
int pw[HA][N];
struct hashInit { hashInit () {
	for (int h = 0; h < HA; h++) {
		pw[h][0] = 1;
		for (int i = 1; i < N; i++) pw[h][i] = int((LL)pw[h][i - 1] * PP[h] % QQ[h]);
	}
} } __init_hash;
struct Hash {
	int v[HA], len;
	Hash () {memset(v, 0, sizeof v); len = 0;}
	Hash (int x) { for (int h = 0; h < HA; h++) v[h] = x; len = 1; }
	friend Hash operator + (const Hash &a, const Hash &b) {
		Hash ret; ret.len = a.len + b.len;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a.v[h] * pw[h][b.len] + b.v[h]) % QQ[h]);
		return ret;
	}
	friend Hash operator + (const Hash &a, const int &b) {
		Hash ret; ret.len = a.len + 1;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a.v[h] * PP[h] + b) % QQ[h]);
		return ret;
	}
	friend Hash operator + (const int &a, const Hash &b) {
		Hash ret; ret.len = b.len + 1;
		for (int h = 0; h < HA; h++) 
			ret.v[h] = int(((LL)a * pw[h][b.len] + b.v[h]) % QQ[h]);
		return ret;
	}
	friend Hash operator - (const Hash &a, const Hash &b) {
		Hash ret; ret.len = a.len - b.len;
		for (int h = 0; h < HA; h++) {
			ret.v[h] = int((a.v[h] - (LL)pw[h][a.len - b.len] * b.v[h]) % QQ[h]);
			if (ret.v[h] < 0) ret.v[h] += QQ[h];
		}
		return ret;
	}
	friend bool operator == (const Hash &a, const Hash &b) {
		for (int h = 0; h < HA; h++) 
			if (a.v[h] != b.v[h]) return false;
		return a.len == b.len;
	}
	friend bool operator < (const Hash &a, const Hash &b) {
		for (int h = 0; h < HA; h++) 
			if (a.v[h] != b.v[h]) return a.v[h] < b.v[h];
		return a.len < b.len;
	}
};

int n;
char s[N];

Hash pre[N], suf[N];


bool ispa(int l, int r) {
	Hash a = pre[r] - pre[l - 1];
	Hash b = suf[l] - suf[r + 1];
	return a == b;
}
int L[N], R[N];

void work() {
	scanf("%s", s + 1);
	n = (int)strlen(s + 1);
	if (n == 1) {
		puts(s + 1);
		return;
	}
	pre[0] = Hash();
	suf[n + 1] = Hash();
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + s[i];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + s[i];
	}
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = min(i, L[i - 1] + 2);
		L[i] = min(L[i], max(0, n - 2 * ((n - i + 1) - 1)));
		if (L[i] < 0) L[i] = 0;
		while (L[i] && !ispa(i - L[i] + 1, i)) L[i]--;
	}
	R[n + 1] = 0;
	for (int i = n; i ; i--) {
		R[i] = min(n - i + 1, R[i + 1] + 2);
		R[i] = min(R[i], max(0, n - 2 * (i - 1)));
		if (R[i] < 0) R[i] = 0;
		while (R[i] && !ispa(i, i + R[i] - 1)) R[i]--;
	}
	int ans = 0;
	vector <int> rec = {0, 0, 0, 0};
	if (R[1] > ans) {
		ans = R[1];
		rec = {R[1], 0, 0, 0};
	}
	if (L[n] > ans) {
		ans = L[n];
		rec = {0, 0, 0, L[n]};
	}
	for(int i=1;i<=n;i++) {
		if(s[i] != s[n-i+1] || i>=n-i+1)break;
		if (2 * i + max(R[i+1], L[n-i]) > ans) {
			ans = 2 * i + max(R[i+1], L[n-i]);
			if (R[i + 1] >= L[n - i]) {
				rec = {i, i + 1, R[i + 1], i};
			}
			else {
				rec = {i, n - i + 1 - L[n - i], L[n - i], i};
			}
		}
	}
	for (int i = 1; i <= rec[0]; i++) putchar(s[i]);
	for (int i = rec[1], j = 0; j < rec[2]; i++, j++) putchar(s[i]); 
	for (int i = n - rec[3] + 1; i <= n; i++) putchar(s[i]);
	putchar('\n');
}

int main() {
	int T;
	read(T);
	while (T--) work();
}