#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[2], b[2];
ll x[2];
int num2[2], num3[2];

void process(int i) {
    while (x[i]%2 == 0) {
        x[i] /= 2, num2[i]++;
    }
    while (x[i]%3 == 0) {
        x[i] /= 3, num3[i]++;
    }
}

void mult23(int i) {
    if (a[i]%3 == 0) a[i] = 2*(a[i]/3);
    else b[i] = 2*(b[i]/3);
}

void div2(int i) {
    if (a[i]%2 == 0) a[i] /= 2;
    else b[i] /= 2;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> a[0] >> b[0] >> a[1] >> b[1];
    x[0] = ll(a[0])*b[0], x[1] = ll(a[1])*b[1];

    process(0), process(1);
    if (x[0] != x[1]) {
        cout << "-1\n";
        return 0;
    }

    int m = 0;
    if (num3[0] > num3[1]) {
        m += num3[0]-num3[1];
        num2[0] += num3[0]-num3[1];
        for (int i=0; i<num3[0]-num3[1]; i++)
            mult23(0);
        num3[0] = num3[1];
    } else {
        m += num3[1]-num3[0];
        num2[1] += num3[1]-num3[0];
        for (int i=0; i<num3[1]-num3[0]; i++)
            mult23(1);
        num3[1] = num3[0];
    }

    if (num2[0] > num2[1]) {
        m += num2[0]-num2[1];
        for (int i=0; i<num2[0]-num2[1]; i++)
            div2(0);
    } else {
        m += num2[1]-num2[0];
        for (int i=0; i<num2[1]-num2[0]; i++)
            div2(1);
    }

    cout << m << '\n';
    cout << a[0] << ' ' << b[0] << '\n';
    cout << a[1] << ' ' << b[1] << '\n';
}