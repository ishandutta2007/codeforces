#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
typedef pair <int, int> ii;

const int Maxn = 262144;
const int nil = 125005;
const int Maxm = 6;
const double PI = acos(-1.0l);

char S[Maxn], T[Maxn];
int slen, tlen;
int rev[Maxn];
base wlen_pw[Maxn];
base A[Maxn], B[Maxn];
vector <ii> seq[Maxn];
int par[Maxm], siz[Maxm];
int comp;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	comp--;
}
 
void fft (base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

void multiply (const ii &p) {
	fill(A, A + Maxn, 0); fill(B, B + Maxn, 0);
	for (int i = 0; i < slen; i++)
		if (S[i] == p.first + 'a') A[i] = 1;
	for (int i = 0; i < tlen; i++)
		if (T[i] == p.second + 'a') B[nil - i] = 1;
	fft(A, Maxn, false); fft(B, Maxn, false);
	for (int i = 0; i < Maxn; i++)
		A[i] *= B[i];
	fft(A, Maxn, true);
	for (int i = 0; i <= slen - tlen; i++)
		if (int(A[i + nil].real() + 0.5) > 0) seq[i].push_back(p);
}

int main()
{
	calc_rev(Maxn, 18);
	scanf("%s", S); slen = strlen(S);
	scanf("%s", T); tlen = strlen(T);
	for (int i = 0; i < Maxm; i++)
		for (int j = 0; j < Maxm; j++) if (i != j)
			multiply(ii(i, j));
	for (int i = 0; i <= slen - tlen; i++) {
		for (int j = 0; j < Maxm; j++)
			par[j] = j, siz[j] = 1;
		comp = Maxm;
		for (int j = 0; j < seq[i].size(); j++)
			unionSet(seq[i][j].first, seq[i][j].second);
		printf("%d%c", Maxm - comp, i + 1 <= slen - tlen? ' ': '\n');
	}
	return 0;
}