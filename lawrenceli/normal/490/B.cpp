#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

int n, a[MAXN], b[MAXN];
map<int, int> back, freq, vis;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        back[a[i]] = b[i];
        freq[a[i]] += 0, freq[b[i]]++;
    }

    vector<int> v, w;
    vis[0] = 1;
    int cur = back[0];
    while (cur) {
        vis[cur] = 1;
        v.push_back(cur);
        cur = back[cur];
    }

    for (typeof(freq.begin()) it = freq.begin(); it != freq.end(); it++)
        if (!vis[it->first] && it->second < 1) {
            cur = it->first; break;
        }

    while (cur) {
        w.push_back(cur);
        cur = back[cur];
    }

    int a=0, b=0;
    while (a<v.size() || b<w.size()) {
        if (b<w.size()) cout << w[b++] << ' ';
        if (a<v.size()) cout << v[a++] << ' ';
    }
}