/*
    21.05.2018 18:08:02
*/

#include <bits/stdc++.h>

using namespace std;

const long long mx = 1000000000;

struct bigint
{
    vector< long long > num;
    bigint() {
        num.assign(10, 0);
    }
    bigint(long long a) {
        num.assign(10, 0);
        num[9] = a % mx;
        num[8] = a / mx;
        // cout << "hi " << num[8] << ' ' << num[9] << '\n';
    }
    bigint(const bigint & a) {
        num.assign(10, 0);
        for (int i = 0; i < 10; ++i)
        {
            num[i] = a.num[i];
        }
    }
    bigint operator+(bigint b)
    {
        bigint v;
        for (int i = 0; i < 10; ++i)
        {
            v.num[i] += num[i] + b.num[i];
            if (v.num[i] >= mx) {
                v.num[i - 1] += v.num[i] / mx;
                v.num[i] = v.num[i] % mx;
            }
        }
        return v;
    }
    bigint operator-(bigint b)
    {
        bigint v;
        for (int i = 0; i < 10; ++i)
        {
            v.num[i] += num[i] - b.num[i];
            while (v.num[i] < 0) {
                v.num[i] += mx;
                v.num[i - 1]--;
            }
        }
        return v;
    }
    bigint operator*(bigint b)
    {
        bigint v;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                long long p = num[i] * b.num[j];
                if (p > 0) {
                    v.num[i + j - 9] += p;
                }
            }
        }
        for (int i = 9; i > 0; i--) {
            v.num[i - 1] += v.num[i] / mx;
            v.num[i] = v.num[i] % mx;
        }
        return v;
    }
    bigint operator/(long long k)
    {
        bigint v;
        for (int i = 0; i < 10; ++i)
        {
            v.num[i] = num[i];
        }
        for (int i = 0; i < 10; ++i)
        {
            if (i < 9) {
                v.num[i + 1] += (v.num[i] % k) * mx;
            }
            v.num[i] = v.num[i] / k;
        }
        return v;
    }
    bool operator>(bigint b)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (num[i] > b.num[i]) {
                return true;
            }
            if (num[i] < b.num[i]) {
                return false;
            }
        }
        return false;
    }
    string show()
    {
        // string s;
        // for (int i = 9; i > -1; i--) {
        //     long long d = 1;
        //     for (int j = 0; j < 9; ++j)
        //     {
        //         s += (char) ((char)'0' + (int)(num[i] % (d * 10ll) / d));
        //         d *= 10ll;
        //     }
        // }
        // reverse(s.begin(), s.end());
        // return s + '\n';
        cout << '|';
        for (int i = 0; i < 10; ++i)
        {
            cout << num[i] << '|';
        }
        cout << endl;
        return "";
    }
};

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 4;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        long long n0, h0;
        cin >> n0 >> h0;
        bigint n(n0), h(h0);
        // cout << n.show() << endl << h.show() << endl;
        long long l = 0, r = 1000000000ll * 1000000000ll * 4ll;
        while (r - l > 1ll) {
            // cout << (r + l) / 2 << endl;
            bigint c((l + r) / 2);
            // cout << c.show() << endl;
            bigint v;
            if (c > h) {
                bigint h0 = (c + h) / 2;
                // cout << "c  = ";
                // c.show();
                // cout << "h  = ";
                // h.show();
                // cout << "h0 = ";
                // h0.show();
                v = h0 * (c + h + c + h - bigint(2) - (h0 - bigint(1)) * bigint(2)) / 2;
                // cout << "v  = ";
                // v.show();
                v = v - (h - bigint(1)) * h / 2;
                // cout << "v  = ";
                // v.show();
                // cout << "\n\n\n";
            }
            else {
                v = c * (c + 1) / 2;
            }
            if (v + 1 > n) {
                r = (l + r) / 2;
            }
            else {
                l = (l + r) / 2;
            }
        }
        cout << r << endl;
    }
    fclose(stdout);
    return 0;
}