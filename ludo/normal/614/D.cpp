#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

#define MAXN 100000

typedef pair<int, int> pii;
typedef long long ll;

int N, A, cf, cm;
ll M;

int a[MAXN];
pii b[MAXN];

ll costmin[MAXN], costmax[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> cf >> cm >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = pii(a[i], i);
    }
    sort(b, b + N);

    costmin[0] = 0;
    for (int i = 1; i < N; i++) {
		if (costmin[i - 1] > 1e15) {
			costmin[i] = 1e15;
			continue;
		}
        costmin[i] = costmin[i - 1] + 1LL * i * (b[i].first - b[i - 1].first);
    }

    costmax[N] = 0;
    for (int i = N; i--; ) {
        costmax[i] = costmax[i + 1] + (A - b[i].first);
    }

    ll maxforce = 0;
    int maxFull = 0, maxMin = 0, maxMinVal = -1;

    for (int nfull = 0; nfull <= N; nfull++) {
        ll cost_full = costmax[N - nfull];

        ll coins_left = M - cost_full;
        if (coins_left < 0) {
            break;
        }

        ll force = nfull * cf;
        int idx, minVal = -1;
        if (nfull == N) {
            idx = 0;
            force += 1LL * A * cm;
        } else {
            idx = upper_bound(costmin, costmin + N - nfull, coins_left) - costmin;
            assert(idx > 0);

			coins_left -= costmin[idx - 1];

			ll maxmin = A; // idx == N ? A : (b[idx].first - 1);
			ll coinsmaxmin = 1LL * idx * (maxmin - b[idx - 1].first);
			coins_left = min(coins_left, coinsmaxmin);

			minVal = 1LL * b[idx - 1].first + coins_left / idx;
			force += 1LL * minVal * cm;

//			 cerr << coins_left << " " << b[idx - 1].first << " -> " << minVal << endl;
        }
//		cerr << nfull << ": " << force << " " << idx << endl << endl;
        if (force > maxforce) {
            maxforce = force;
            maxFull = nfull;
            maxMin = idx;
            maxMinVal = minVal;
        }
    }
//	cerr << maxforce << " " << maxFull << " " << maxMin << " " << maxMinVal << endl;
    for (int i = 0; i < maxFull; i++) {
        a[b[N - 1 - i].second] = A;
    }
    for (int i = 0; i < maxMin; i++) {
        a[b[i].second] = maxMinVal;
    }
    cout << maxforce << endl;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " \n"[i == N - 1];
    }
    return 0;
}