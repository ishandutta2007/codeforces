#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1010;
int n;
char s[maxn], ans[maxn];

int query() {
    printf("%s\n", s + 1);
    fflush(stdout);
    int x; scanf("%d", &x);
    if (x == -1 || x == n) exit(0);
    return x;
}

void print() {
    for (int i = 1; i <= n; ++i) s[i] = ans[i];
    query();
    printf("ERR\n");
    exit(0);
}

int main() {
    scanf("%d", &n);
    fill(s + 1, s + n + 1, 'T');
    int v1 = query();
    if (v1 == n) return 0;
    if (v1 == 0)
        fill(ans + 1, ans + n + 1, 'F'), print();
    if (n <= 600) {
        for (int i = 1; i <= n; ++i) {
            s[i] = 'F';
            if (query() > v1) ans[i] = 'F';
            else ans[i] = 'T';
            s[i] = 'T';
        }
        print();
    }

    for (int i = 2; i <= n; i += 2) s[i] = 'F';
    int v2 = query();
    for (int i = 1, j = n; i <= j; i += 2) {
        if (i == j) {
            fill(s + 1, s + n + 1, 'T');
            s[i] = 'F';
            if (query() > v1) ans[i] = 'F';
            else ans[i] = 'T';
            break;
        }
        fill(s + 1, s + n + 1, 'T');
        s[i] = s[i + 1] = 'F';
        int x = query() - v1;
        if (x == 2) ans[i] = ans[i + 1] = 'F';
        else if (x == -2) ans[i] = ans[i + 1] = 'T';
        else {
            if (j == i + 1) j = 1;
            fill(s + 1, s + n + 1, 'T');
            for (int o = 2; o <= n; o += 2) s[o] = 'F';
            s[i] = 'F', s[i + 1] = 'T', s[j] ^= 'T' ^ 'F';
            x = query() - v2;
            if (x == 3) ans[i] = 'F', ans[i + 1] = 'T', ans[j] = 'F';
            if (x == 1) ans[i] = 'F', ans[i + 1] = 'T', ans[j] = 'T';
            if (x == -1) ans[i] = 'T', ans[i + 1] = 'F', ans[j] = 'F';
            if (x == -3) ans[i] = 'T', ans[i + 1] = 'F', ans[j] = 'T';
            if (s[j] == 'T') ans[j] ^= 'T' ^ 'F';
            --j;
        }
    }
    print();
	return 0;
}