#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int n, a[maxn], b[maxn], freq[maxn];
bool in[maxn];
int p = -1, q = -1;

void go(int pos) {
    for (int i = 1; i <= n; i++)
        if (freq[i] == 0) {
            int bef = a[pos];
            a[pos] = i;
            int num = 0;
            for (int j = 0; j < n; j++)
                if (b[j] == a[j]) num++;
            if (num == n - 1) {
                for (int j = 0; j < n; j++) cout << a[j] << ' ';
                exit(0);
            }
            a[pos] = bef;
        }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) freq[a[i]]++;

    for (int i = 0; i < n; i++)
        if (freq[a[i]] > 1) {
            go(i);
        }
}