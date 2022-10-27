#include <bits/stdc++.h>
#include <chrono>
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);
using namespace std;
typedef long long LL;
typedef long double LD;
int TN = 1;
void showDeque(deque<int> d) {
    int n = d.size();
    for (int i = 0; i < n; i++) {
        cout << d.front() << " ";
        d.push_back(d.front());
        d.pop_front();
    }
    cout << endl << "==" << endl;
}
void solve() {
    int n;
    int q;
    cin >> n >> q;
    deque<int> d;
    int maxValue = -1;
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        d.push_back(a_i);
        maxValue = max(maxValue, a_i);
    }
    map<int, pair<int, int>> answer;
    int maxIndex = 0;
    while (true) {
        int first = d.front();
        d.pop_front();
        int second = d.front();
        d.pop_front();
        if (first == maxValue) {
            d.push_front(second);
            d.push_front(first);
            break;
        }
        maxIndex++;
        answer[maxIndex] = {first, second};
        if (second > first) {
            swap(first, second);
        }
        d.push_front(first);
        d.push_back(second);
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = d.front();
        d.pop_front();
    }
    for (int i = 0; i < q; i++) {
        LL m_j;
        cin >> m_j;
        if (m_j <= maxIndex) {
            cout << answer[m_j].first << " " << answer[m_j].second << '\n';
        } else {
            cout << maxValue << " " << a[(m_j - (maxIndex + 1)) % (n - 1) + 1] << '\n';
        }
    }
}
int main() {
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    while (TN--) solve();
    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";
    return 0;
}