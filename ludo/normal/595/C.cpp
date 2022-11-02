#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 200000

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream &out, const pii &a)
{
    return out << '(' << a.first << ", " << a.second << ')';
}
istream& operator>>(istream &in, pii &a)
{
    return in >> a.first >> a.second;
}

int n, a[MAX], nxt[MAX], prv[MAX];
set<pii> heap;

int main()
{
#ifdef LOCAL
    // assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int ans = 1e9 + 1;
    for (int i = 0; i < n / 2; i++) {
        ans = min(ans, a[i + n / 2] - a[i]);
    }
    cout << ans << endl;
    return 0;
    /*
    for (int i = 1; i < n; i++) {
		a[i - 1] = a[i] - a[i - 1];
    }
    n--;

    prv[0] = nxt[n - 1] = -1;
    for (int i = 0; i + 1 < n; i++) {
        nxt[i] = i + 1;
        prv[i + 1] = i;
    }

    for (int i = 1; i < n; i++) {
        heap.insert(pii(a[i - 1] + a[i], i));
    }

//    for (int i = 0; i < n; i++) {
//        cerr << a[i] << " ";
//    }
//    cerr << endl;
//
//    for(auto it = heap.begin(); it != heap.end(); ++it) {
//        cerr << *it << " ";
//    }
//    cerr << endl;

    int left = 0, right = n - 1;
    bool vova = true;
    while (n > 1) {
        n--;

        if (vova) {
            // check ends
            if (a[left] >= a[right]) {
                // break left
                int nl = nxt[left];
                heap.erase(pii(a[left] + a[nl], nl));
                left = nl;
                prv[left] = -1;
            } else {
                // break right
                int pr = prv[right];
                heap.erase(pii(a[pr] + a[right], right));
                right = pr;
                nxt[right] = -1;
            }
        } else {
            // check minimum
            int val = heap.begin()->first;
            int min_r = heap.begin()->second;
            heap.erase(heap.begin());

            int min_l = prv[min_r];
            assert(min_l != -1);

            int r = nxt[min_r];
            if (r != -1) {
				heap.erase(pii(a[min_r] + a[r], r));
				heap.insert(pii(val + a[r], r));
            }

            int l = prv[min_r] = prv[min_l];
            if (l != -1) {
				heap.erase(pii(a[l] + a[min_l], min_l));
				heap.insert(pii(a[l] + val, min_r));
                nxt[l] = min_r;
            } else {
                assert(left == min_l);
                left = min_r;
            }

			a[min_r] = val;
//            cerr << "r and l are " << r << " " << l << endl;
        }
        vova = !vova;

//		cerr << left << ", " << right << ": ";
//        for(auto it = heap.begin(); it != heap.end(); ++it) {
//            cerr << *it << " ";
//        }
//        cerr << endl;
//
//        int cur = left;
//        while (cur != -1) {
//			cerr << a[cur] << " ";
//			cur = nxt[cur];
//        }
//        cerr << endl << endl;
    }

//    for(auto it = heap.begin(); it != heap.end(); ++it) {
//        cerr << *it << " ";
//    }
//    cerr << endl;
//    cerr << "LEFT RIGHT " << left << " " << right << endl;

    assert(left == right);

    cout << a[left] << endl;
    return 0;
    */
}