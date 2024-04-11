#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int N = 5005;

char buffer[N];

inline void readLine(string& s) {
    scanf("%s", buffer);
    s = buffer;
}

int k, n;
string s[N];

int main() {


#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &k, &n);

    vec< int > CNT(26), TMP(26);

    for(int i = 1;i <= k;i++) {
        readLine(s[i]);
    }

    sort(s + 1, s + k + 1);
    k = unique(s + 1, s + k + 1) - (s + 1);

    for(int i = 1;i <= k;i++) {
        if(i == 1) {
            for(char c : s[i]) {
                CNT[c - 'a']++;
            }
        }else {
            TMP.assign(26, 0);
            for(char c : s[i]) {
                TMP[c - 'a']++;
            }
            for(int j = 0;j < 26;j++) {
                if(TMP[j] != CNT[j]) {
                    puts("-1");
                    return 0;
                }
            }
        }
    }

    if(k == 1) {
        swap(s[1][0], s[1][n - 1]);
        printf("%s\n", s[1].c_str());
        return 0;
    }

    vec< int > pos;

    for(int i = 0;i < n;i++) {
        if(s[1][i] != s[2][i]) {
            pos.push_back(i);
        }
    }

    assert(!pos.empty());

    int any2 = *max_element(ALL(CNT)) >= 2;

    for(int j1 : pos) {
        for(int j2 : pos) {
            if(j1 >= j2) continue;
            int ok = 1;
            swap(s[1][j1], s[1][j2]);
            for(int i = 2;i <= k && ok;i++) {
                int p1 = -1;
                int p2 = -1;
                for(int j = 0;j < n;j++) {
                    CNT[s[i][j] - 'a']++;
                    if(s[1][j] != s[i][j]) {
                        if(p1 == -1) {
                            p1 = j;
                        }else if(p2 == -1) {
                            p2 = j;
                        }else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if(p1 != -1 && p2 != -1 && (s[1][p1] != s[i][p2] || s[1][p2] != s[i][p1])) {
                    ok = 0;
                    break;
                }
                if(p1 != -1 && p2 == -1) {
                    ok = 0;
                    break;
                }
                if(p1 == -1 && p2 == -1 && !any2) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                printf("%s\n", s[1].c_str());
                return 0;
            }else {
                swap(s[1][j1], s[1][j2]);
            }
        }
    }

    double const MAXTIME = 0.67 * CLOCKS_PER_SEC;

    pos.clear();

    for(int i = 0;i < n;i++) {
        pos.push_back(i);
    }

    int const ITER = 40;
    int iter = 0;

    for(int j1 : pos) {
        if(iter++ % ITER == 0 && clock() > MAXTIME) goto MARK;
        for(int j2 : pos) {
            if(iter++ % ITER == 0 && clock() > MAXTIME) goto MARK;
            if(j1 >= j2) continue;
            int ok = 1;
            swap(s[1][j1], s[1][j2]);
            for(int i = 2;i <= k && ok;i++) {
                if(iter++ % ITER == 0 && clock() > MAXTIME) goto MARK;
                int p1 = -1;
                int p2 = -1;
                for(int j = 0;j < n;j++) {
                    if(iter++ % ITER == 0 && clock() > MAXTIME) goto MARK;
                    CNT[s[i][j] - 'a']++;
                    if(s[1][j] != s[i][j]) {
                        if(p1 == -1) {
                            p1 = j;
                        }else if(p2 == -1) {
                            p2 = j;
                        }else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if(p1 != -1 && p2 != -1 && (s[1][p1] != s[i][p2] || s[1][p2] != s[i][p1])) {
                    ok = 0;
                    break;
                }
                if(p1 != -1 && p2 == -1) {
                    ok = 0;
                    break;
                }
                if(p1 == -1 && p2 == -1 && !any2) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                printf("%s\n", s[1].c_str());
                return 0;
            }else {
                swap(s[1][j1], s[1][j2]);
            }
        }
    }

    MARK:;

    puts("-1");

    return 0;
}