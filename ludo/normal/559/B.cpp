#include <bits/stdc++.h>

using namespace std;

string A, B;

#define SIGMA (1 << 8)

//#undef LOCAL

int cntAL[SIGMA], cntAR[SIGMA];
int cntBL[SIGMA], cntBR[SIGMA];

bool is_equivalent(int ia, int ib, int n)
{
    if (n & 1) {
		// odd
		for (int i = 0; i < n; i++) {
			if (A[i + ia] != B[i + ib]) {
				return false;
			}
		}
		return true;
    } else {
		bool are_equal = true;
		int hn = n / 2;
		for (int c = 'a'; c <= 'z'; c++) {
			cntAL[c] = cntBL[c] = cntAR[c] = cntBR[c] = 0;
		}

		for (int i = 0; i < hn; i++) {
			cntAL[(int) A[i + ia]]++;
			cntBL[(int) B[i + ib]]++;
			are_equal &= A[i + ia] == B[i + ib];
		}
		for (int i = hn; i < n; i++) {
			cntAR[(int) A[i + ia]]++;
			cntBR[(int) B[i + ib]]++;
			are_equal &= A[i + ia] == B[i + ib];
		}

		if (are_equal) return true;

		bool r2a = true, r2b = true;
		for (int c = 'a'; c <= 'z'; c++) {
			r2a &= cntAL[c] == cntBL[c] && cntAR[c] == cntBR[c];
			r2b &= cntAL[c] == cntBR[c] && cntAR[c] == cntBL[c];
		}

		return (r2a && is_equivalent(ia, ib, hn) && is_equivalent(ia + hn, ib + hn, hn)) ||
				(r2b && is_equivalent(ia, ib + hn, hn) && is_equivalent(ia + hn, ib, hn));
//		bool ret = (r2a && is_equivalent(ia, ib, hn) && is_equivalent(ia + hn, ib + hn, hn)) ||
//				(r2b && is_equivalent(ia, ib + hn, hn) && is_equivalent(ia + hn, ib, hn));
//		cerr << ia << " " << ib << " " << n << endl;
//		return 	ret;
    }
}

void run()
{
    if (is_equivalent(0, 0, A.size())) {
		cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
}

void gen(int len)
{
	srand(time(NULL));

	A.resize(len);
	B.resize(len);
	for (int i = 0; i < len; i++) {
		A[i] = 'a' + (rand() % 4);
		B[i] = 'a' + (rand() % 4);
	}
}

int main()
{
#ifdef LOCAL

	gen(200000);
	run();
	return 0;

	assert(freopen("input.txt", "r", stdin));
	while (true) {
		cin >> A >> B;
		if (!cin) break;

		run();
	}
#else
	cin >> A >> B;
	run();
#endif // LOCAL
    return 0;
}