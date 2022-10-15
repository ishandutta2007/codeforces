#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e3 + 5;

const LL LO = -2e12, HI = 2e12;

struct node {
	int l, r;
	LL v, d; bool cl;
} t[N * N];

int tcnt = 0;

void clear(int &x) {
	if (!x) return;
	t[x].cl = 1;
	t[x].d = 0;
	t[x].v = 0;
}

void add(int &x, LL l, LL r, LL d) {
	if (!x) x = ++tcnt;
	t[x].v += d * (r - l + 1);
	t[x].d += d;
}

void add(int &x, LL l, LL r, LL ql, LL qr) {
	if (!x) x = ++tcnt;
	if (l == ql && r == qr) t[x].v += r - l + 1, t[x].d ++;
	else {
		LL mid = l + (r - l) / 2;
		if (t[x].cl) {
			clear(t[x].l);
			clear(t[x].r);
			t[x].cl = 0;
		}
		if (t[x].d) {
			add(t[x].l, l, mid, t[x].d);
			add(t[x].r, mid + 1, r, t[x].d);
			t[x].d = 0;
		}
		if (qr <= mid) add(t[x].l, l, mid, ql, qr);
		else if (ql >  mid) add(t[x].r, mid + 1, r, ql, qr);
		else add(t[x].l, l, mid, ql, mid), add(t[x].r, mid + 1, r, mid + 1, qr);
		t[x].v = t[t[x].l].v + t[t[x].r].v;
	}
}

LL qry(int x, LL l, LL r, LL ql, LL qr) {
	if (!x) return 0;
	if (l == ql && r == qr) return t[x].v;
	else {
		LL mid = l + (r - l) / 2;
		if (t[x].cl) {
			clear(t[x].l);
			clear(t[x].r);
			t[x].cl = 0;
		}
		if (t[x].d) {
			add(t[x].l, l, mid, t[x].d);
			add(t[x].r, mid + 1, r, t[x].d);
			t[x].d = 0;
		}
		if (qr <= mid) return qry(t[x].l, l, mid, ql, qr);
		else if (ql >  mid) return qry(t[x].r, mid + 1, r, ql, qr);
		else return qry(t[x].l, l, mid, ql, mid) + qry(t[x].r, mid + 1, r, mid + 1, qr);
	}
	assert (false);
}


void clr(int &x, LL l, LL r, LL ql, LL qr) {
	if (!x) return ;
	if (l == ql && r == qr) t[x].v = 0, t[x].cl = 1, t[x].d = 0;
	else {
		LL mid = l + (r - l) / 2;
		if (t[x].cl) {
			clear(t[x].l);
			clear(t[x].r);
			t[x].cl = 0;
		}
		if (t[x].d) {
			add(t[x].l, l, mid, t[x].d);
			add(t[x].r, mid + 1, r, t[x].d);
			t[x].d = 0;
		}
		if (qr <= mid) clr(t[x].l, l, mid, ql, qr);
		else if (ql >  mid) clr(t[x].r, mid + 1, r, ql, qr);
		else clr(t[x].l, l, mid, ql, mid), clr(t[x].r, mid + 1, r, mid + 1, qr);
		t[x].v = t[t[x].l].v + t[t[x].r].v;
	}
}



int n;

int main() {
	scanf("%d", &n);
	LL cur = 0;
	int rt = 0;
	LL ans = 0;
//	vector <int> check;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (i % 2) {
			add(rt, LO, HI, cur + 1, cur + x);
			cur += x;
		} else {
			ans += qry(rt, LO, HI, cur - x + 1, cur);
			clr(rt, LO, HI, cur - x + 2, HI);
			cur -= x;
		}
	}
/*	int chk = 0;
	for (int i = 0; i < check.size(); i++) {
		for (int j = i, sum = 0; j < check.size(); j++) {
			sum += check[j];
			if (sum < 0)break;
			if (sum == 0) chk++;
		}
	}*/
	printf("%lld\n", ans);
//	cerr << chk << endl;
}