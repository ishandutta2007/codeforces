#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111 , inf = 1000111222;
char ans[4];

bool query(int a, int b) {
    cout << "1 " << a << ' ' << b << endl;
    fflush(stdout);
    cin >> ans;
    return ans[0] == 'T';
}

int getp(int l, int r) {
    //cout << "#" << ' ' << l << ' ' << r << endl;
    while (l < r) {
        int mid = (l + r) / 2;
        if (query(mid, mid + 1)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;

    int fst = getp(1, n), scd = -1, th = -1;
    int a1 = fst, a2;
    if (fst < n) {
        scd = getp(fst + 1, n);
    }
    if (fst > 1) {
        th = getp(1, fst - 1);
    }
    //cout << scd << ' ' << th << endl;
    if (scd == -1) {
        cout << "2 " << fst << ' ' << th << endl;
        return 0;
    } else if (th == -1) {
        cout << "2 " << fst << ' ' << scd << endl;
        return 0;
    }
    if (scd == fst + 1 && query(scd, fst) == 0) {
        cout << "2 " << fst << ' ' << th << endl;
        return 0;
    } else {
        cout << "2 " << fst << ' ' << scd << endl;
        return 0;
    }

    return 0;
}