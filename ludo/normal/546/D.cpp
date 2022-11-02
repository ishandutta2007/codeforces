#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

//#define MAXN 100000
#define MAXN 5000000

bool isprime[MAXN + 1];
int nfactors[MAXN + 1], sfactors[MAXN + 1];

void find_primes()
{
    for (int i = MAXN; i > 0; i--) {
        isprime[i] = true;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (isprime[i]) {
            int j = 1;
            while (j <= MAXN / i) {
				j *= i;
				for (int k = j; k <= MAXN; k += j) {
					nfactors[k]++;
				}
            }
        }
    }
    for (int i = 1; i <= MAXN; i++) {
		sfactors[i] = sfactors[i - 1] + nfactors[i];
    }
}

int main()
{
//	freopen("input.txt", "w", stdout);
//	cout << 1000000 << endl;
//	for (int i = 0; i < 1000000; i++) {
//		cout << (4 * i + 14) << " " << (2 * i + 102) << endl;
//	}
//	return 0;


#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL
    find_primes();

    int t, a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        cout << (sfactors[a] - sfactors[b]) << "\n";
    }
    return 0;
}