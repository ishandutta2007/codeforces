#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int my[max_n];
int his[max_n];
int prm[max_n];
int prh[max_n];
int n;

int summy(int add, int cnt) {
    if (cnt <= add) {
        return add * 100;
    }
    int ans = add * 100;
    cnt -= add;
    if (cnt == 0) return ans;
    return ans + prm[cnt - 1];
}

int sumhis(int add, int cnt) {
    cnt = min(cnt, n);
    if (cnt == 0) return 0;
    return prh[cnt - 1];
}

bool check(int ans) {
    int cnt = ans - ans / 4;
    int add = ans - n;
    if (summy(add, cnt) >= sumhis(add, cnt)) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            scanf("%d", my + i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", his + i);
        }
        sort(my, my + n);
        sort(his, his + n);
        reverse(my, my + n);
        reverse(his, his + n);
        for (int i = 0; i < n; ++i) {
            prm[i] = my[i];
            prh[i] = his[i];
            if (i) {
                prm[i] += prm[i - 1];
                prh[i] += prh[i - 1];
            }
        }


        for (int ans = n;;++ans){
            if (check(ans)) {
                cout << ans - n << "\n";
                break;
            }
        }
    }

    return 0;
}