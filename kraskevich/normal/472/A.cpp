#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 10;

bool p[N];

int main() {
    ios_base::sync_with_stdio(0);
    fill(p, p + N, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i < N; i++)
        if (p[i])
            for (int j = i * i;  j < N; j += i)
                p[j] = false;
    int n;
    cin >> n;
    for (int i = 2; ; i++)
        if (!p[i] && !p[n - i]) {
            cout << i << " " << n - i;
            return 0;
         } 
    return 0;
}