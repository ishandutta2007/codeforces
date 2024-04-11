#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_k = 258, inf = 1000111222;

int gr[max_k];
int n, k;
vector<int> v;

int get_gr(int c) {
    while (c && gr[c - 1] == gr[c]) {
        c--;
    }
    return c;
}
int max_gr = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_k; ++i) {
        gr[i] = -1;
    }
    cin >> n >> k;
    int c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        v.PB(c);
    }
    for (int i = 0; i < n; ++i) {
        int cur = v[i];
        if (gr[cur] != -1) {
            cout << get_gr(cur) << ' ';
            continue;
        }
        int st = get_gr(cur);
        if (cur - st + 1 >= k || st == 0) {
            st = max(st, cur - k + 1);
            for (int j = st; j <= cur; ++j) {
                gr[j] = max_gr;
            }
            max_gr++;
        } else {
            st = get_gr(st - 1);
            if (cur - st + 1 <= k) {
                for (int j = st; j <= cur; ++j) {
                    gr[j] = gr[st];
                }
            } else {
                st = get_gr(cur);
                for (int j = st; j <= cur; ++j) {
                    gr[j] = max_gr;
                }
                max_gr++;
            }
        }
        cout << get_gr(cur) << ' ';
    }

    return 0;
}