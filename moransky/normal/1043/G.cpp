#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

const int N = 200005, S = 18;

int n, t, q, m = 221, p, sum[N][26], b = 121;

int L[N], R[N], v[N];

int sa[N], cnt[N], rk[N], oldrk[N << 1], id[N], height[N];

multiset<int> A, B;

vector<int> insL[N], insR[N], delL[N], delR[N];

int st[N][S], Log[N];

char s[N];

ULL H[N], P[N];


int inline queryST(int l, int r) {
	if (l > r) swap(l, r);
	++l;
	int k = Log[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}

ULL inline queryHash(int l, int r) {
	return H[r] - H[l - 1] * P[r - l + 1]; 
}


//sjjs

bool inline check1(int l, int r) {
	int len = r - l + 1;
	for (int i = 2; i * i <= len; i++) {
		if (len % i == 0) {
			while (len % i == 0) len /= i;
			int o = (r - l + 1) / i;
			if (queryST(rk[l], rk[l + o]) >= r - l + 1 - o) return true;
		}
	}
	if (len != 1) {
		int o = (r - l + 1) / len;
		if (queryST(rk[l], rk[l + o]) >= r - l + 1 - o) return true;
	}
	return false;
}

// bool inline check1(int l, int r) {
// 	int len = r - l + 1;
// 	for (int i = 1; i * i <= len; i++) {
// 		if (len % i == 0) {
// 			if (i != len && queryHash(l, r - i) == queryHash(l + i, r)) return true;
// 			int p = len / i;
// 			if (p != len && queryHash(l, r - p) == queryHash(l + p, r)) return true; 
// 		}
// 	}
// 	return false;

bool inline check2(int l, int r) {
	int len = r - l + 1;
	if (L[l] && L[l] * 2 <= len) return true;
	if (R[r] && R[r] * 2 <= len) return true;
	for (int i = 1; i <= min(t, len / 2); i++)
		if (queryHash(l, l + i - 1) == queryHash(r - i + 1, r)) return true;
	int L = max(1, rk[l] - t - 1);
	int R = min(n, rk[l] + t + 1);
	int v = height[rk[l]];
	for (int i = rk[l] - 1; i >= L; i--) {
		if (sa[i] > l && sa[i] <= r && sa[i] + v - 1 >= r) return true;
		v = min(v, height[i]);
	}
	v = 2e9;
	for (int i = rk[l] + 1; i <= R; i++) {
		v = min(v, height[i]);
		if (sa[i] > l && sa[i] <= r && sa[i] + v - 1 >= r) return true;
	}
	return false;
}

bool inline check3(int l, int r) {
	if (v[r] >= l) return true;
	if (sum[r][s[r] - 'a'] - sum[l - 1][s[r] - 'a'] > 1) return true;
	if (sum[r][s[l] - 'a'] - sum[l - 1][s[l] - 'a'] > 1) return true; 
	return false;
}

bool inline check4(int l, int r) {
	for (int i = 0; i < 26; i++) 
		if (sum[r][i] - sum[l - 1][i] > 1) return true;
	return false;
}

bool inline cmp(int i, int j, int k) {
	return oldrk[i] == oldrk[j] && oldrk[i + k] == oldrk[j + k]; 
}

void inline SA() {
	for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
	for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for (int i = n; i; i--) sa[cnt[rk[i]]--] = i;
	for (int w = 1; w < n; w <<= 1, m = p) {
		p = 0;
		for (int i = n; i > n - w; i--) id[++p] = i;
		for (int i = 1; i <= n; i++)
			if (sa[i] > w) id[++p] = sa[i] - w;
		for (int i = 0; i <= m; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) cnt[rk[i]]++, oldrk[i] = rk[i];
		for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for (int i = n; i; i--) sa[cnt[rk[id[i]]]--] = id[i];
		p = 0;
		for (int i = 1; i <= n; i++)
			rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
	}
	for (int i = 1; i <= n; i++) {
		int j = sa[rk[i] - 1], k = max(0, height[rk[i - 1]] - 1);
		while (s[i + k] == s[j + k]) k++;
		height[rk[i]] = k;
	}
	for (int i = 1; i <= n; i++) st[i][0] = height[i];
	for (int j = 1; j < S; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}


int inline queryLt(int a, int b) {
	int l = 1, r = a;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (queryHash(a - mid + 1, a) == queryHash(b - mid + 1, b)) l = mid;
		else r = mid - 1;
	}
	return r;
}

void inline prework() {
	for (int w = 1; w <= n; w++) {
		for (int b = 2 * w; b <= n; b += w) {
			int a = b - w;
			if (s[a] == s[b]) {
				int Rt = min(queryST(rk[a], rk[b]), w);
				int Lt = min(queryLt(a, b), w);
				int La = a - Lt + 1, Ra = a + Rt - 1 - w + 1;
				if (La <= Ra) {
					insL[La].push_back(w);
					delL[Ra + 1].push_back(w);
					insR[La + 2 * w - 1].push_back(w);
					delR[Ra + 2 * w].push_back(w);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < insL[i].size(); j++) A.insert(insL[i][j]);
		for (int j = 0; j < insR[i].size(); j++) B.insert(insR[i][j]);
		for (int j = 0; j < delL[i].size(); j++) A.erase(A.find(delL[i][j]));
		for (int j = 0; j < delR[i].size(); j++) B.erase(B.find(delR[i][j]));
		if (!A.empty()) L[i] = *A.begin();
		if (!B.empty()) R[i] = *B.begin();
	}
	for (int i = 1; i <= n; i++) v[i] = max(v[i - 1], R[i] ? (i - 2 * R[i] + 1) : 0);
}

int main() {
	scanf("%d%s%d", &n, s + 1, &q);
	for (int i = 1; i <= n; i++) Log[i] = log2(i);
	P[0] = 1, t = sqrt(n);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i - 1] * b;
		H[i] = H[i - 1] * b + s[i];
		for (int j = 0; j < 26; j++) 
			sum[i][j] = sum[i - 1][j];
		sum[i][s[i] - 'a']++;
	}
	SA();
	prework();
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		// 1:  AA
		if (check1(l, r)) puts("1");
		// 2: AAB, BAA, ABA
		else if (check2(l, r)) puts("2");
		// 3: BAAC, ABAC, BACA
		else if (check3(l, r)) puts("3");
		// 4: 
		else if (check4(l, r)) puts("4");
		else puts("-1");
	}
	return 0;
}