#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1000005;

int n;
char s[N];
int pos_le[N];
int pos_ri[N];
int mas_le[N];
int mas_ri[N];
int size_le = 0;
int size_ri = 0;
ll sum_le[N];
ll sum_ri[N];
ll res[N];

void upd() {
    size_le = 0;
    size_ri = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] == 'U') { // R
            mas_ri[size_ri] = i;
            pos_ri[i] = size_ri;
            size_ri++;
        }else { // L
            mas_le[size_le] = i;
            pos_le[i] = size_le;
            size_le++;
        }
    }

    sum_le[0] = mas_le[0];

    for(int i = 1;i < size_le;i++) {
        sum_le[i] = sum_le[i - 1] + mas_le[i];
    }

    sum_ri[0] = mas_ri[0];

    for(int i = 1;i < size_ri;i++) {
        sum_ri[i] = sum_ri[i - 1] + mas_ri[i];
    }

    int cnt_le = 0;
    int cnt_ri = 0;
    int ql, qr;

    ql = +inf;
    qr = -inf;

    for(int i = n - 1;i >= 0;i--) {
        if(s[i] == 'D') {
            cnt_le++;
            ql = min(ql, pos_le[i]);
            qr = max(qr, pos_le[i]);
        }
    }

    //for(int i = 0;i < size_le;i++) cout << mas_le[i] << " ";
    //cout << "\n";

    for(int i = 0;i < n;i++) {
        if(s[i] == 'U') {

            int p = pos_ri[i];

            //cout << cnt_ri << " " << cnt_le << "  !!\n";

            if(cnt_le == 0) {
                res[i] = n - i;
            }else if(cnt_ri == 0) {
                res[i] = mas_le[ql] - i + mas_le[ql] + 1;
            }else if(cnt_ri >= cnt_le) {
                res[i] = (sum_le[qr] - (ql ? sum_le[ql - 1] : 0)) - ((p? sum_ri[p - 1] : 0 ) - (p - cnt_le > 0 ? sum_ri[p - cnt_le - 1] : 0));
                res[i] += (sum_le[qr] - sum_le[ql]) - ((p ? sum_ri[p - 1] : 0) - sum_ri[p - cnt_le]);
                res[i] += mas_le[ql] - i;
                res[i] += n - mas_ri[p - cnt_le];
            }else {
                res[i] += (sum_le[ql + cnt_ri] - sum_le[ql]) - ((p ? sum_ri[p - 1] : 0));
                res[i] += (sum_le[ql + cnt_ri - 1] - (ql ? sum_le[ql - 1] : 0)) - ((p ? sum_ri[p - 1] : 0));
                res[i] += mas_le[ql] - i;
                res[i] += mas_le[ql + cnt_ri] + 1;
            }

            cnt_ri++;
        }else {
            cnt_le--;
            ql++;
        }
    }
}

bool solve() {

    scanf("%d %s", &n, s);

    upd();

    for(int i = 0;i < n / 2;i++) {
        swap(s[i], s[n - 1 - i]);
        swap(res[i], res[n - 1 - i]);
    }

    for(int i = 0;i < n;i++) {
        if(s[i] == 'U') s[i] = 'D';
        else s[i] = 'U';
    }

    upd();

    for(int i = 0;i < n;i++) {
        printf("%I64d ", res[n - 1 - i]);
    }

    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}