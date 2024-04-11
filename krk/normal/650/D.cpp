#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 800005;
const int mod1 = 1015538387;
const int mod2 = 1000000009;

struct pos {
	int val, h1, h2;
	pos(): val(0), h1(0), h2(0) {}
	void addPos(const pos &b) {
		if (b.val < val) return;
		if (b.val > val) { val = b.val; h1 = 0; h2 = 0; }
		h1 = (h1 + b.h1) % mod1; h2 = (h2 + b.h2) % mod2;
	}
};

int n, m;
int H[Maxn];
vector <int> un;
vector <int> my[Maxn];
pos myL[Maxn], myR[Maxn];
bool inall[Maxn];
pos BITL[Maxn], BITR[Maxn];
int qind[Maxn], qval[Maxn];
int L[Maxn], R[Maxn];

pos GetL(int x)
{
	pos p;
	for (int i = x - 1; i > 0; i -= i & -i)
		p.addPos(BITL[i]);
	return p;
}

void UpdateL(int x, pos p)
{
	for (int i = x; i <= un.size() + 1; i += i & -i)
		BITL[i].addPos(p);
}

pos GetR(int x)
{
	pos p;
	for (int i = x + 1; i <= un.size() + 1; i += i & -i)
		p.addPos(BITR[i]);
	return p;
}

void UpdateR(int x, pos p)
{
	for (int i = x; i > 0; i -= i & -i)
		BITR[i].addPos(p);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
		un.push_back(H[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &qind[i], &qval[i]);
		un.push_back(qval[i]);
		my[qind[i]].push_back(i);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 1; i <= n; i++) {
		H[i] = lower_bound(un.begin(), un.end(), H[i]) - un.begin() + 1;
		for (int j = 0; j < my[i].size(); j++) {
			int ind = my[i][j];
			qval[ind] = lower_bound(un.begin(), un.end(), qval[ind]) - un.begin() + 1;
			L[ind] = GetL(qval[ind]).val;
		}
		pos p = GetL(H[i]); 
		if (p.val == 0) { p.h1 = (p.h1 + 1) % mod1; p.h2 = (p.h2 + 1) % mod2; }
		myL[i] = p;
		p.val++;
		UpdateL(H[i], p);
	}
	pos G = GetL(un.size() + 1);
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < my[i].size(); j++) {
			int ind = my[i][j];
			R[ind] = GetR(qval[ind]).val;
		}
		pos p = GetR(H[i]);
		if (p.val == 0) { p.h1 = (p.h1 + 1) % mod1; p.h2 = (p.h2 + 1) % mod2; }
		myR[i] = p;
		p.val++;
		UpdateR(H[i], p);
		if (G.val == myL[i].val + myR[i].val + 1 && 
			G.h1 == ll(myL[i].h1) * myR[i].h1 % mod1 && 
			G.h2 == ll(myL[i].h2) * myR[i].h2 % mod2)
			inall[i] = true;
	}
	for (int i = 1; i <= m; i++) {
		int opt1 = G.val;
		if (inall[qind[i]]) opt1--;
		int opt2 = L[i] + R[i] + 1;
		printf("%d\n", max(opt1, opt2));
	}
	return 0;
}