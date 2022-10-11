#include <bits/stdc++.h>
using namespace std;

long long n;
int k;
priority_queue<int> pq;
multiset<int> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    if (__builtin_popcountll(n) > k) {
        return cout << "No", 0;
    }
    for (int i = 0; i < 63; i++) {
        if (n >> i & 1) {
            pq.push(i);
        }
    }

    cout << "Yes\n";
    while (pq.size() < k) {
        int u = pq.top(); pq.pop();
        pq.push(u - 1); pq.push(u - 1);
    }
    int mx = pq.top();
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 0; i < 63; i++) {
        if (n >> i & 1) {
            se.insert(i);
        }
    }
    while (*prev(se.end()) > mx) {
        int u = *prev(se.end()); se.erase(prev(se.end()));
        se.insert(u - 1); se.insert(u - 1);
    }
    while (se.size() < k) {
        int u = *se.begin(); se.erase(se.begin());
        se.insert(u - 1); se.insert(u - 1);
    }
    while (!se.empty()) {
        cout << *prev(se.end()) << " ";
        se.erase(prev(se.end()));
    }
}