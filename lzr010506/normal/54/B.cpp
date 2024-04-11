#include <bits/stdc++.h>
#define vst vector<string>
#define pb push_back
#define sz size
#define mp make_pair
#define fst first
#define sec second
#define pii pair<int, int>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;

vst rotate(const vst &a)
{
	vst res;
	FOR(i, 0, (int)(a[0]).sz() - 1)
	{
		string s;
		for (int j = (int)(a).sz() - 1; j >= 0; j --)
			s += a[j][i];
		res.pb(s);
	}
	return res;
}

vst min_rotate(const vst &a)
{
	vst res = a, A = a;
	FOR(i, 0, 3)
	{
		A = rotate(A);
		res = min(res, A);
	}
	return res;
}

bool check(const vector<vst> &v)
{
	vector<vst> A((int)(v).sz());
	FOR(i, 0, (int)(v).sz() - 1)
		FOR(j, 0, 4)
			A[i] = min_rotate(v[i]);
	FOR(i, 0, (int)(v).sz() - 1)
		FOR(j, i + 1, (int)(v).sz() - 1)
			if (A[i] == A[j]) return false;
	return true;
}

bool cmp(const pii &a, const pii &b)
{
	int x = a.fst * a.sec, y = b.fst * b.sec;
	if (x != y) return x < y;
	else return a.fst < b.fst;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vst a(n);
	FOR(i, 0, n - 1) cin >> a[i];
	vector<pii> res;
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (n % i == 0 && m % j == 0) 
			{
				vector<vst> A;
				FOR(p, 0, n / i - 1)
					FOR(q, 0, m / j - 1)
					{
						vst tmp;
						FOR(t, 0, i - 1)
							tmp.pb(a[p * i + t].substr(q * j, j));
						A.pb(tmp);
					}
				if (check(A)) res.pb(mp(i, j));
			}
	cout << (int)(res).sz() << endl;
	sort((res).begin(), (res).end(), cmp);
	cout << res[0].fst << " " << res[0].sec << endl;
	return 0;
}