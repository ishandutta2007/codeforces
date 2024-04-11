#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 201;

int n, c[N], d1[N], d2[N], ask[N];

int kol[N];

int main()
{
    n = 4;
    kol[1] = 1;
    kol[2] = 0;
    kol[3] = 1;
    kol[4] = 2;
    kol[5] = 0;
    kol[6] = 6;
    for (int i = 1; i <= n; i++)
        d1[0] += (kol[i] - 1) * kol[i] * (kol[i] - 2) / 6, d2[0] += kol[i] * kol[i + 1] * kol[i + 2];

    cin >> n >> d1[0] >> d2[0];
    //cout << d1[0] << ' ' << d2[0] << endl;
    for (int i = n - 1; i >= 3; i--)
        ask[n - i] = i;
    ask[n - 2] = 1;
    ask[n - 1] = 2;
    ask[n] = 1;
    for (int i = 1; i <= n; i++) {
        cout << "+ " << ask[i] << endl;
        kol[ask[i]]++;
        for (int j = 1; j <= n; j++)
            d1[i] += (kol[j] - 1) * kol[j] * (kol[j] - 2) / 6, d2[i] += kol[j] * kol[j + 1] * kol[j + 2];
        //cout << d1[i] << ' ' << d2[i] << endl;
        cin >> d1[i] >> d2[i];
    }
    if (d1[n] - d1[n - 1] == 0)
        c[1] = 0;
    else {
        int d = 1 + (d1[n] - d1[n - 1]) * 8;
        c[1] = (-1 + sqrt(d)) / 2;
    }
    int x2 = d2[n] - d2[n - 1], x1 = d2[n - 2] - d2[n - 3];
    c[3] = x2 - x1 - 1;
    c[2] = x1 / (c[3] + 1);
    int del = d2[n - 1] - d2[n - 2];
    c[4] = (del - (c[3] + 1) * (c[1] + 1)) / (c[3] + 1) - (4 != n);
    for (int i = 3; i + 2 <= n; i++) {
        int del = d2[n - i] - d2[n - i - 1];
        c[i + 2] = (del - c[i - 2] * c[i - 1] - (c[i + 1] + 1) * c[i - 1]) / (c[i + 1] + 1);
        if (i + 2 != n)
            c[i + 2]--;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << c[i] << ' ';
    cout << endl;
    return 0;
}