#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e15;
int N, M, K;
vector <pair <int, int> > dep[1000006], arr[1000006];
long long cur[100005];
long long bestDep[1000006], bestArr[1000006];
int mnDep[100005], mxArr[100005];

int main(void) {
    cin >> N >> M >> K;
    int d, f, t, c;
    for (int i = 1; i <= N; ++i) mnDep[i] = 1000001;
    for (int i = 0; i < M; ++i) {
        cin >> d >> f >> t >> c;
        if (f == 0) arr[d].push_back(make_pair(t, c)), mxArr[t] = max(mxArr[t], d);
        else dep[d].push_back(make_pair(f, c)), mnDep[f] = min(mnDep[f], d);
    }
    for (int i = 1; i <= N; ++i) cur[i] = oo;
    for (int i = 1; i <= 1000000; ++i) {
        bestDep[i] = bestDep[i-1];
        for (auto x: dep[i]) if (cur[x.first] > x.second) {
            if (cur[x.first] < oo) bestDep[i] -= cur[x.first];
            cur[x.first] = x.second;
            bestDep[i] += cur[x.first];
        }
    }
    for (int i = 1; i <= N; ++i) cur[i] = oo;
    for (int i = 1000000; i >= 1; --i) {
        bestArr[i] = bestArr[i+1];
        for (auto x: arr[i]) if (cur[x.first] > x.second) {
            if (cur[x.first] < oo) bestArr[i] -= cur[x.first];
            cur[x.first] = x.second;
            bestArr[i] += cur[x.first];
        }
    }

    int L = 0, R = 1000001;
    for (int i = 1; i <= N; ++i) L = max(L, mnDep[i]), R = min(R, mxArr[i]);
    long long ans = oo;
    for (int i = L + 1; i + K <= R; ++i) ans = min(ans, bestDep[i-1] + bestArr[i+K]);
    if (ans == oo) ans = -1;
    cout << ans << endl;
}