/*
    17.05.2018 20:39:26
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

long long gcd(long long a, long long b)
{
    if (a > b) {
        swap(a, b);
    }
    while (a != 0) {
        b = b % a;
        swap(a, b);
    }
    return b;
}

long long gcd1(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd1 (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 3;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, m, x, y, vx, vy;
        cin >> n >> m >> x >> y >> vx >> vy;
        if (vx == 0) {
            if (x == 0) {
                if (vy > 0) {
                    cout << 0 << ' ' << m << '\n';
                }
                else {
                    cout << "0 0\n";
                }
            }
            else if (x == n) {
                if (vy > 0) {
                    cout << n << ' ' << m << endl;
                }
                else {
                    cout << n << " 0\n";
                }
            }
            else {
                cout << -1 << endl;
            }
            continue;
        }
        if (vy == 0) {
            if (y != 0 && y != m) {
                cout << -1 << endl;
            }
            else {
                if (vx > 0) {
                    cout << n << ' ';
                }
                else {
                    cout << "0 ";
                }
                cout << y << endl;
            }
            continue;
        }
        long long a = n * vy;
        long long b = m * vx;
        long long c = x * vy - y * vx;
        long long d = gcd(abs(a), abs(b));
        if (abs(c) % abs(d) != 0) {
            cout << -1 << endl;
            continue;
        }
        c = c / d;
        a = a / d;
        b = b / d;
        long long p, q;
        gcd1(abs(a), abs(b), p, q);
        p *= c;
        q *= c;
        if (a != abs(a)) {
            p = -p;
        }
        if (b != abs(b)) {
            q = -q;
        }
        // p = p % b;
        // while (p < 0) {
        //     p += abs(b);
        // }
        // q = q % a;
        // while (q < 0) {
        //     q += abs(a);
        // }
        // if (vx < 0) {
        //     p -= abs(b);
        // }
        // if (vy < 0) {
        //     q -= abs(a);
        // }
        long long t, t1, t2, t3, nowp;
        if (vx > 0) {
            t1 = (p - 1) / b;
            t2 = t1 + 1;
            t3 = t1 - 1;
            t = t1;
            nowp = -1;
            if (nowp == -1 || abs(p - b * t1 - 1) < nowp) {
                if (p - b * t1 >= 1) {
                    t = t1;
                    nowp = p - b * t1 - 1;
                }
            }
            if (nowp == -1 || abs(p - b * t2 - 1) < nowp) {
                if (p - b * t2 >= 1) {
                    t = t2;
                    nowp = p - b * t2 - 1;
                }
            }
            if (nowp == -1 || abs(p - b * t3 - 1) < nowp) {
                if (p - b * t3 >= 1) {
                    t = t3;
                    nowp = p - b * t3 - 1;
                }
            }
        }
        else {
            t1 = p / b;
            t = t1;
            t2 = t1 + 1;
            t3 = t1 - 1;
            nowp = -1;
            if (nowp == -1 || abs(p - b * t1) < nowp) {
                if (p - b * t1 <= 0) {
                    t = t1;
                    nowp = abs(p - b * t1);
                }
            }
            if (nowp == -1 || abs(p - b * t2) < nowp) {
                if (p - b * t2 <= 0) {
                    t = t2;
                    nowp = abs(p - b * t2);
                }
            }
            if (nowp == -1 || abs(p - b * t3) < nowp) {
                if (p - b * t3 <= 0) {
                    t = t3;
                    nowp = abs(p - b * t3);
                }
            }
        }
        p = p - b * t;
        q = q + a * t;
        long long cnt = 0;
        if (vx > 0) {
            cnt = p - 1;
        }
        else {
            cnt = -p;
        }
        if (cnt % 2 != 0) {
            vx = -vx;
        }
        if (vy > 0) {
            cnt = q - 1;
        }
        else {
            cnt = -q;
        }
        if (cnt % 2 != 0) {
            vy = -vy;
        }
        if (vx == 1) {
            cout << n << ' ';
        }
        else {
            cout << 0 << ' ';
        }
        if (vy == 1) {
            cout << m << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    fclose(stdout);
    return 0;
}