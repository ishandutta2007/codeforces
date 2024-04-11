#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1200;

int old[N];
int cur[N];

void makeStep(int x) {
    int d = 0;
    fill(cur, cur + N, 0);
    for (int i = 0; i < N; i++) {
        bool big = true;
        if (d % 2 == 1)
            big = false;
        d += old[i];
        int h1 = old[i] / 2;
        int h2 = old[i] - old[i] / 2;
        if (!big)
            swap(h1, h2);
        cur[i] += h1;
        cur[i ^ x] += h2;
    }
    for (int i = 0; i < N; i++)
        old[i] = cur[i];
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        old[a]++;
    }
    for (int i = 0; i < k; i++)
        makeStep(x);
    int l = 0;
    int r = N - 1;
    while (!old[l])
        l++;
    while (!old[r])
        r--;
    cout << r << " " << l << endl;
}