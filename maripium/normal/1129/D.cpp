#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
const int SQ = 400;
const int NSQ = 256;
const int mod = 998244353;

void add(int &x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

void sub(int &x,int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
}

int n, k;
int lst[N];
int to[N];
int ad[NSQ];
int sm[NSQ][N + N];
int nw[N];
int f[N];

void addOne(int pos,int val) {
	int bl = pos / SQ;
	if (val == 1) {
		sub(sm[bl][N + nw[pos]], f[pos]);
		++nw[pos];
	} else {
		--nw[pos];
		add(sm[bl][N + nw[pos]], f[pos]);
	}
}

void addRange(int bl,int val) {
	ad[bl] += val;
}

void addSeg(int l,int r,int val) {
	while (l < r && l % SQ) {
		addOne(l, val);
		++l;
	}
	
	while ((l / SQ) < (r / SQ)) {
		addRange(l / SQ, val);
		l += SQ;
	}
	
	while (l < r) {
		addOne(l, val);
		++l;
	}
}

int getOne(int pos) {
	int bl = pos / SQ;
	if (nw[pos] + ad[bl] <= k) {
		return f[pos];
	} else {
		return 0;
	}
}

int getRange(int bl) {
	return sm[bl][N + k - ad[bl]];
}

int getSeg(int l,int r) {
	int ans = 0;
	while (l < r && l % SQ) {
		add(ans, getOne(l));
		++l;
	}
	
	while ((l / SQ) < (r / SQ)) {
		add(ans, getRange(l / SQ));
		l += SQ;
	}
	
	while (l < r) {
		add(ans, getOne(l));
		++l;
	}
	
	return ans;
}

void rebuild(int bl) {
	memset(sm[bl], 0, sizeof sm[bl]);
	ad[bl] = 0;
	int l = bl * SQ, r = min((bl + 1) * SQ, n);
	for (int i = l; i < r; ++i) {
		add(sm[bl][N + nw[i]], f[i]);
	}
	for (int i = 1; i < N + N; ++i) {
		add(sm[bl][i], sm[bl][i - 1]);
	}
}

int main() {
	
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; ++i) {
		lst[i] = -1;
	}
	
	f[0] = 1;
	for (int i = 0; i < n; ++i) {
		int x;
		
		scanf("%d", &x);
		to[i] = lst[x];
		lst[x] = i;
		
		if (to[i] == -1) {
			addSeg(0, i + 1, 1);
		} else {
			addSeg(to[to[i]] + 1, to[i] + 1, -1);
			addSeg(to[i] + 1, i + 1, 1);
		}
		
		f[i + 1] = getSeg(0, i + 1);
		if ((i + 1) % SQ == SQ - 1) {
			rebuild((i + 1) / SQ);
		}
	}
	
	printf("%d\n", f[n]);
}