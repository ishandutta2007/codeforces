
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// we need some subset of the columns to be covered by one array,
// and the complement to be covered by the other array.
// For subset A, find the array i which maximizes the minimum entry in a column of A.
// For subset A', find array j that maximizes minimum entry of a column in A'.

const int N = 3e5 + 5, M = 8, INF = 2e9;
int n, m;
int a[N][M];
int b[N][1 << M];
int c[1 << M];
int d[1 << M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        b[i][0] = INF;
        for(int s = 1; s < (1 << m); s++) {
            int j = s & -s;
            b[i][s] = min(b[i][s - j], a[i][(int) log2(j)]);
            if(b[i][s] >= d[s]) {
                d[s] = b[i][s];
                c[s] = i;
            }
        }
    }
    int best = 0, besti = 0, bestj = 0;
    for(int s = 0; s < (1 << m); s++) {
        int s2 = (1 << m) - 1 - s;
        int val = min(d[s], d[s2]);
        if(val >= best) {
            best = val;
            besti = c[s];
            bestj = c[s2];
        }
    }
    cout << (besti + 1) << " " << (bestj + 1) << endl;
}