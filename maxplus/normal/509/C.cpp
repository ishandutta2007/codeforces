#include <iostream>

using namespace std;

struct longnum{
    int l, a[401];
    int &operator[](int x)
    {
        return a[x];
    }
    void gtn()
    {
        int i = l;
        int sum = 0;
        longnum minc(int ds, int ml);
        while (i--)
        {
            if (sum && a[i] != 9)
            {
                a[i]++;
                sum--;
                for (int j = l - 1; j > i; --j)
                    if (sum >= 9)
                        a[j] = 9, sum -= 9;
                    else
                        a[j] = sum, sum = 0;
                return;
            }
            if (i == 0)
            {
                sum = 0;
                for (int i = 0; i < l; ++i)
                    sum += a[i];
                *this = minc(sum, l + 1);
                return;
            }
            sum += a[i];
        }
    }
    void z(longnum &ln)
    {
        int sum = 0, t = 0;
        for (int i = 0; i < l; ++i)
            sum += a[i];
        for (int i = 0; i < l; ++i)
        {
            t = min(sum, ln[i]);
            sum -= t;
            a[i] = t;
            if (sum == 0)
            {
                for (int j = i + 1; j < l; ++j)
                    a[j] = 0;
                break;
            }
        }
        if (sum > 0)
        {
            for (int i = l - 1; i > 0; --i)
            {
                sum += a[i];
                a[i] = min(sum, 9);
                sum -= a[i];
            }
        }
    }
    void swap(longnum &b)
    {
        std::swap(l, b.l);
        std::swap(a, b.a);
    }
};

bool operator<(longnum &a, longnum &b)
{
    if (a.l != b.l)
        return a.l < b.l;
    for (int i = 0; i < a.l; ++i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return 0;
}

longnum a;
longnum minc(int ds, int ml)
{
    a.l = (ds + 8) / 9;
    for (int i = a.l - 1; ds >= 9; --i)
        a[i] = 9, ds -= 9;
    if (ds != 0)
        a[0] = ds;
    int m = ml - a.l;
    if (m <= 0)
        return a;
    a[0]--;
    for (int i = a.l - 1; i >= 0; --i)
        a[i + m] = a[i];
    for (int i = m - 1; i > 0; --i)
        a[i] = 0;
    a[0] = 1;
    a.l += m;
    return a;
}

longnum ln, nln;

int main()
{
    int n = 300, b = 300;
    cin >> n;
    cin >> b;
    ln = minc(b, 0);
    for (int i = 0; i < ln.l; ++i)
        cout << ln[i];
    for (int i = 1; i < n; ++i)
    {
        cout << '\n';
        cin >> b;
        nln = minc(b, ln.l);
        if (nln < ln)
            nln.z(ln);
        while (!(ln < nln))
            nln.gtn();
        nln.swap(ln);
        for (int i = 0; i < ln.l; ++i)
            cout << ln[i];
    }
    return 0;
}