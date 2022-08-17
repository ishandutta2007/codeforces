#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_c = 30, inf = 1000111222;

string s;

char buf[max_n];

string reads() {
    scanf("%s", buf);
    return buf;
}

int cnt[max_n][max_c];

int get_cnt(int from, int to, char c) {
    int res = cnt[to][c];
    if (from) {
        res -= cnt[from - 1][c];
    }
    return res;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    s = reads();
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i) {
            for (int c = 0; c < max_c; ++c) {
                cnt[i][c] = cnt[i - 1][c];
            }
        }
        cnt[i][s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        if (l == r) {
            puts("Yes");
            continue;
        }
        if (s[l] != s[r]) {
            puts("Yes");
            continue;
        }
        int cs = 0;
        for (int i = 0; i < max_c; ++i) {
            if (get_cnt(l, r, i)) {
                ++cs;
            }
        }
        if (cs >= 3) {
            puts("Yes");
            continue;
        }
        puts("No");
    }



    return 0;
}