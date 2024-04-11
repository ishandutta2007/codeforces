#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int Maxm = 605;
const int Maxl = 2405;
const int Maxb = 64;
const int Maxd = 38;

struct pos {
	ull has[Maxd];
	int hlen;
	int id;
	pos(int id = -1): id(id), hlen(0) { }
	void Set(int b) {
		int ind = b / Maxb;
		while (hlen <= ind)
			has[hlen++] = 0;
		has[ind] |= ull(1) << b % Maxb;
	}
	void Xr(const pos &b) {
		int mn = min(hlen, b.hlen);
		for (int i = 0; i < mn; i++)
			has[i] ^= b.has[i];
		for (int i = mn; i < b.hlen; i++)
			has[hlen++] = b.has[i];
		while (hlen > 0 && has[hlen - 1] == 0) hlen--;
	}
	int Get(int b)
	{
		int ind = b / Maxb;
		if (ind >= hlen) return 0;
		return bool(has[ind] & (ull(1) << b % Maxb));
	}
};

int m;
char s[Maxm];
int slen;
pos B[Maxl], BP[Maxl];
pos P;

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		P = pos(i);
		scanf("%s", s); slen = strlen(s);
		int pnt = 0;
		int b = 0;
		ull bas = ull(1) << 32;
		while (pnt < slen) {
			ull car = 0;
			for (int i = pnt; i < slen; i++) {
				car = ull(10) * car + ull(s[i] - '0');
				s[i] = car / bas + '0'; car %= bas;
			}
			while (pnt < slen && s[pnt] == '0') pnt++;
			for (int i = 0; i < 32; i++)
				if (car & ull(1) << i) P.Set(b + i);
			b += 32;
		}

		pos res;
		bool en = false;
		for (int b = Maxl - 1; b >= 0; b--)
			if (P.Get(b))
				if (B[b].id != -1) { res.Xr(BP[b]); P.Xr(B[b]); }
				else { en = true; B[b] = P; BP[b] = res; BP[b].Set(i); break; }
		if (en) printf("0\n");
		else {
			vector <int> r;
			for (int j = 0; j < i; j++)
				if (res.Get(j)) r.push_back(j);
			printf("%d", r.size());
			for (int i = 0; i < r.size(); i++)
				printf(" %d", r[i]);
			printf("\n"); 
		}
	}
	return 0;
}