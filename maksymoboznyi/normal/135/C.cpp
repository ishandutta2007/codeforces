#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

string s;
int a, b, mn[3], mx[3], k[N][3];

bool check1(int p1, int p2) {
    if (p1 >= p2 || p1 == -1 || p2 == -1)
        return 0;
    int x = 0, y = 0;
    if (p1 > 0)
        x = k[p1 - 1][0];
    int del = 0;
    if (x < b && p1 > 0)
        if (x + k[p1 - 1][2] >= b)
            del = (b - x), k[p1 - 1][2] -= (b - x), x = b;
    if (x < b)
        return 0;

    y = k[p2 - 1][1] + (k[p2 - 1][2] - k[p1][2]);
    if (p1 > 0)
        y  += k[p1 - 1][2], k[p1 - 1][2] += del;
    return y >= a;
}

bool check2(int p1, int p2) {
    if (p1 >= p2 || p1 == -1 || p2 == -1)
        return 0;
    int x = 0, y = 0;
    int del = 0;
    if (p1 > 0)
        x = k[p1 - 1][1];
    if (x < a && p1 > 0)
        if (x + k[p1 - 1][2] >= a)
            del = (a - x), k[p1 - 1][2] -= (a - x), x = a;
    if (x < a)
        return 0;
    y = k[p2 - 1][0] + (k[p2 - 1][2] - k[p1][2]);
    if (p1 > 0)
        y  += k[p1 - 1][2], k[p1 - 1][2] += del;
    return y >= b;
}

int main()
{
    cin >> s;
    b = (s.size() - 2) / 2;
    a = s.size() - 2 - b;
    mn[0] = mn[1] = -1;
    mx[0] = mx[1] = -1;
    mx[2] = mn[2] = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0') {
            if (mn[0] == -1)
                mn[0] = i;
            mx[0] = i;
        } else if (s[i] == '1'){
            if (mn[1] == -1)
                mn[1] = i;
            mx[1] = i;
        } else {
            if (mn[2] == -1)
                mn[2] = i;
            mx[2] = i;
        }
    k[0][0] = (s[0] == '0');
    k[0][1] = (s[0] == '1');
    k[0][2] = (s[0] == '?');
    for (int i = 1; i < s.size(); i++) {
        k[i][0] = k[i - 1][0] + (s[i] == '0');
        k[i][1] = k[i - 1][1] + (s[i] == '1');
        k[i][2] = k[i - 1][2] + (s[i] == '?');
    }
    int n = s.size();
    ///00
    //cout << k[n - 1][1] << endl;
    //cout << int(s.size()) - (k[n - 1][1] + k[n - 1][1] - 1) << endl;
    if (int(s.size()) - (k[n - 1][1] + k[n - 1][1] - 1) >= 2)
        cout << "00\n";
    ///01
    bool was = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0' || s[i] == '?')
            if (check1(i, mx[1]) || check1(i, mx[2]))
                was = 1;
    if (was) {
        cout << "01\n";
    }
    ///10
    was = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1' || s[i] == '?')
            if (check2(i, mx[0]) || check2(i, mx[2]))
                was = 1;
    if (was) {
        cout << "10\n";
    }
    ///11
    if (int(s.size()) - (k[n - 1][0] + k[n - 1][0]) >= 2)
        cout << "11\n";
    return 0;
}