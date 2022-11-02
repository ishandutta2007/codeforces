#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 3005;

int n, p[MAXN], m, num;
bool vis[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    cin >> m;
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            vector<int> v;
            int cur = i;
            do {
                v.push_back(cur);
                vis[cur] = 1;
                cur = p[cur];
            } while (cur != i);
            num += v.size()-1;
        }
    if (num == m) {
        cout << "0\n";
        return 0;
    } else if (num > m) {
        int cnt = 0;
        cout << num-m << '\n';
        for (int i=0; i<n && cnt<num-m; ) {
            for (int j=0; j<n; j++) vis[j] = 0;
            int cur = i;
            do {
                vis[cur] = 1;
                cur = p[cur];
            } while (cur != i);
            bool b = 0;
            for (int j=i+1; j<n; j++)
                if (vis[j]) {
                    cout << i+1 << ' ' << j+1 << ' ';
                    swap(p[i], p[j]);
                    b = 1;
                    cnt++;
                    break;
                }
            if (!b) i++;
        }
        return 0;
    } else {
        int cnt = 0;
        cout << m-num << '\n';
        for (int i=0; i<n && cnt<m-num; ) {
            for (int j=0; j<n; j++) vis[j] = 0;
            int cur = i;
            do {
                vis[cur] = 1;
                cur = p[cur];
            } while (cur != i);
            bool b = 0;
            for (int j=i+1; j<n; j++)
                if (!vis[j]) {
                    cout << i+1 << ' ' << j+1 << ' ';
                    swap(p[i], p[j]);
                    b = 1;
                    cnt++;
                    break;
                }
            if (!b) i++;
        }
        return 0;
    }
}