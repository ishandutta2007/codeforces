#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;
const int M[2] = {1000000007, 1000000007};

int n, m;
int N;
char s[MAXN];
char t[MAXN];
int h[4][26][MAXN];
int p[2][MAXN];

void process(int n, char s[], int mid, int h[][MAXN] ) {
    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= n; i++) {
            h[c][i] = h[c][i - 1];
            if (c == s[i] - 'a') {
                h[c][i] += p[mid][i];
                if (h[c][i] >= M[mid] ) {
                    h[c][i] -= M[mid];
                }
            }
        }
    }

    // cerr << "S = " << s + 1 << "\n";

    // for (int c = 0; c < 3; c++) {
    //     for (int i = 1; i <= n; i++) {
    //         cerr << h[c][i] << " ";
    //     }
    //     cerr << "\n";
    // }
    // cerr << "---------------------\n";
}

int get_hash(int c, int h[][MAXN], int mid, int l, int r) {
    long long value = h[c][r] - h[c][l - 1] + M[mid];
    value *= p[mid][N - r];
    value %= M[mid];
    return value;
}

bool check_substring(int l, int r) {
    vector<pair<long long, long long> > a, b;

    for (int c = 0; c < 26; c++) {
        int first = get_hash(c, h[0], 0, l, r);
        int second = get_hash(c, h[1], 1, l, r);
        long long _first = first * 1000000400ll + second;

        int third = get_hash(c, h[2], 0, 1, m);
        int fourth = get_hash(c, h[3], 1, 1, m);
        long long _second = third * 1000000400ll + fourth;

        a.push_back(make_pair(_first, _second ) );
        b.push_back(make_pair(_second, _first ) );
    }

    sort(a.begin(), a.end() );
    sort(b.begin(), b.end() );

    for (int c = 0; c < 26; c++) {
        if (a[c] != b[c] ) {
            return false;
        }
    }

    return true;
}

void solve() {
    scanf("%d%d", &n, &m);
    N = n + 5;

    scanf("%s", s + 1);
    scanf("%s", t + 1);

    p[0][0] = p[1][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p[0][i] = (int)( (p[0][i - 1] * 3ll) % M[0] );
        p[1][i] = (int)( (p[1][i - 1] * 5ll) % M[1] );
    }

    process(n, s, 0, h[0] );
    process(n, s, 1, h[1] );
    process(m, t, 0, h[2] );
    process(m, t, 1, h[3] );

    vector<int> answer;

    for (int i = 1; i + m - 1 <= n; i++) {
        int l = i;
        int r = i + m - 1;
        if (check_substring(l, r) ) {
            answer.push_back(i);
        }
    }

    printf("%d\n", (int)answer.size() );
    for (int a : answer) {
        printf("%d ", a);
    }
    printf("\n");
}

int main() {
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
    return 0;
}