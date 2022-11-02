#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int spd = 86400; //seconds per day
const int spy = 31536000; //seconds per non leap yaer

int sy = 1970;

//number leap years <= yr
int numly(int yr) {
    return yr / 4 - yr / 100 + yr / 400;
}

ll nums(int yr) {
    ll ret = ll(spy) * (yr - sy);
    ret += ll(spd) * (numly(yr - 1) - numly(sy - 1));
    return ret;
}

int search(ll t) {
    int lo = 0, hi = 100000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (nums(mid + sy) > t) hi = mid;
        else lo = mid + 1;
    }
    return lo + sy;
}

int s, m, h, day, date, month, n;
ll t;

int sd[405];
int ft[405];

int months[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int yr) {
    return yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0);
}

vector<int> vt;

bool good(int d, int dat) {
    if (day == -1 && date == -1) return 1;
    if (day == -1) return dat == date;
    if (dat == -1) return d == day;
    return day == d || date == dat;
}

void init() {
    int cs = 0, cm = 0, ch = 0;
    for (int ct = 0; ct < spd; ct++) {
        if ((s == -1 || s == cs) && (m == -1 || m == cm) && (h == -1 || h == ch)) vt.push_back(ct);
        cs++;
        if (cs == 60) cm++, cs = 0;
        if (cm == 60) ch++, cm = 0;
    }
    assert(ch == 24 && cm == 0 && cs == 0);

    memset(ft, -1, sizeof(ft));
    int d = 4;
    for (int ii = sy; ii < sy + 400; ii++) {
        int i = ii % 400;
        sd[i] = d;
        if (leap(i)) months[2] = 29;
        else months[2] = 28;
        int dat = 1, mth = 1, ct = 0;
        while (mth < 13) {
            if (good(d, dat) && (month == -1 || month == mth) && ft[i] == -1) ft[i] = ct + vt[0];
            d = (d + 1) % 7;
            ct += spd;
            if (dat < months[mth]) dat++;
            else mth++, dat = 1;
        }
    }
    assert(d == 4);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s >> m >> h >> day >> date >> month >> n;
    day %= 7;
    init();

    for (int i = 0; i < n; i++) {
        cin >> t;
        int yr = search(t);
        //cout << yr << ' ' << nums(yr) << endl;
        ll ans = -1;
        for (int j = 0; j < 400; j++)
            if (ft[(j + yr) % 400] != -1) {
                ans = nums(j + yr) + ft[(j + yr) % 400];
                break;
            }
        assert(ans != -1);

        int d = sd[(yr + 399) % 400], dat = 1, mth = 1;
        ll ct = nums(yr - 1);
        if (leap(yr - 1)) months[2] = 29;
        else months[2] = 28;
        while (mth < 13) {
            if (ct + spd > t && good(d, dat) && (month == -1 || month == mth)) {
                bool b = 0;
                for (int j : vt)
                    if (ct + j > t) {
                        ans = min(ans, ct + j);
                        b = 1;
                        break;
                    }
                if (b) break;
            }

            d = (d + 1) % 7;
            ct += spd;
            if (dat < months[mth]) dat++;
            else mth++, dat = 1;
        }

        cout << ans << '\n';
    }
}