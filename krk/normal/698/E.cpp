#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int secsInDay = 86400;
const int daysInYear = 365;
const int daysInWeek = 7;
const int Maxp = 400;

int daysInYears[Maxp + 1];
int s, m, h, weekday, day, month;
int T;
ll num;

bool Leap(int y) { return y % 400 == 0 || y % 100 != 0 && y % 4 == 0; }

int daysInMonth(int y, int m)
{
    if (m == 2) return Leap(y)? 29: 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

ll getDays(int y, int m, int d)
{
    ll res = 0;
    y--;
    res = y / Maxp * daysInYears[Maxp];
    y %= Maxp;
    res += daysInYears[y];
    for (int i = 1; i < m; i++)
        res += daysInMonth(y + 1, i);
    res += d - 1;
    return res;
}

int getTime(int h, int m, int s)
{
    return h * 60 * 60 + m * 60 + s;
}

void toDate(ll days, int &y, int &m, int &d)
{
    y = days / daysInYears[Maxp] * Maxp;
    days %= daysInYears[Maxp];
    int p = 0;
    while (days >= daysInYears[p + 1]) p++;
    y += p;
    days -= daysInYears[p];
    y++;
    m = 1;
    while (days >= daysInMonth(y, m)) {
        days -= daysInMonth(y, m);
        m++;
    }
    d = days + 1;
}

void toTime(int secs, int &h, int &m, int &s)
{
    s = secs % 60; secs /= 60;
    m = secs % 60; secs /= 60;
    h = secs;
}

bool checkDay(int cy, int cm, int cd, int wday)
{
    if (month != -1 && month != cm) return false;
    if (day != -1 && weekday != -1) return cd == day || wday == weekday;
    if (day != -1) return cd == day;
    if (weekday != -1) return wday == weekday;
    return true;
}

bool checkTime(int a, int b, int c)
{
    if (h != -1 && h != a) return false;
    if (m != -1 && m != b) return false;
    if (s != -1 && s != c) return false;
    return true;
}

void nextDay(int &cy, int &cm, int &cd, int &wday)
{
    if (++cd > daysInMonth(cy, cm)) {
        cd = 1;
        if (++cm > 12) {
            cm = 1;
            cy++;
        }
    }
    wday = wday % daysInWeek + 1;
}

void Solve(int &cy, int &cm, int &cd, int &wday, int &a, int &b, int &c)
{
    while (true) {
        if (!checkDay(cy, cm, cd, wday)) {
            nextDay(cy, cm, cd, wday);
            a = b = c = 0;
        } else if (!checkTime(a, b, c)) {
            if (++c >= 60) {
                c = 0;
                if (++b >= 60) {
                    b = 0;
                    if (++a >= 24) {
                        a = 0;
                        nextDay(cy, cm, cd, wday);
                    }
                }
            }
        } else break;
    }
}

int main()
{
    cin >> s >> m >> h >> weekday >> day >> month;
    for (int i = 1; i <= Maxp; i++)
        daysInYears[i] = daysInYears[i - 1] + daysInYear + int(Leap(i));
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &num); num++;
        ll sh = getDays(1970, 1, 1);
        num += sh * secsInDay;
        int wday = (3 - sh % daysInWeek + daysInWeek) % daysInWeek + 1;
        int y, mon, d;
        int a, b, c;
        toDate(num / secsInDay, y, mon, d);
        toTime(num % secsInDay, a, b, c);
        wday = (wday + num / secsInDay - 1) % daysInWeek + 1;
        Solve(y, mon, d, wday, a, b, c);
        num = (ll(getDays(y, mon, d)) - sh) * secsInDay + getTime(a, b, c);
        printf("%I64d\n", num);
    }
    return 0;
}