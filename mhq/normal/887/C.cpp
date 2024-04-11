#include <bits/stdc++.h>
using namespace std;
int a[25];
int b[25];
bool check() {
    for (int i = 0; i <= 5; i++) {
        int color = b[4 * i + 1];
        for (int j = 1; j <= 4; j++) {
            if (b[4 * i + j] != color) return false;
        }
    }
    return true;
}
int main() {
    for (int i = 1; i <= 24; i++) {
        cin >> a[i];
    }
    for (int i = 13; i <= 16; i++) {
        b[i] = a[i];
    }
    for (int i = 17; i <= 20; i++) {
        b[i] = a[i];
    }
    b[5] = a[1]; b[7] = a[3]; b[9] = a[5]; b[11] = a[7]; b[22] = a[11]; b[24] = a[9]; b[1] = a[24]; b[3] = a[22];
    b[2] = a[2]; b[4] = a[4]; b[6] = a[6]; b[8] = a[8]; b[10] = a[10]; b[12] = a[12]; b[21] = a[21]; b[23] = a[23];
    if (check()) {
        cout << "YES";
        return 0;
    }
    b[1] = a[5]; b[3] = a[7]; b[5] = a[9]; b[7] = a[11]; b[11] = a[22]; b[9] = a[24]; b[24] = a[1]; b[22] = a[3];
    if (check()) {
        cout << "YES";
        return 0;
    }
    for (int i = 5; i <= 8; i++) {
        b[i] = a[i];
    }
    for (int i = 21; i <= 24; i++) {
        b[i] = a[i];
    }
    b[1] = a[1]; b[2] = a[2]; b[18] = a[18]; b[20] = a[20]; b[12] = a[12]; b[11] = a[11]; b[15] = a[15]; b[13] = a[13];
    b[17] = a[3]; b[19] = a[4]; b[10] = a[17]; b[9] = a[19]; b[14] = a[9]; b[16] = a[10]; b[4] = a[14]; b[3] = a[16];
    if (check()) {
        cout << "YES";
        return 0;
    }
    b[3] = a[17]; b[4] = a[19]; b[17] = a[10]; b[19] = a[9]; b[9] = a[14]; b[10] = a[16]; b[14] = a[4]; b[16] = a[3];
    if (check()) {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i <= 4; i++) {
        b[i] = a[i];
    }
    for (int i = 9; i <= 12; i++) {
        b[i] = a[i];
    }
    b[15] = a[15]; b[16] = a[16]; b[7] = a[7]; b[8] = a[8]; b[19] = a[19]; b[20] = a[20]; b[23] = a[23]; b[24] = a[24];
    b[13] = a[5]; b[14] = a[6]; b[5] = a[17]; b[6] = a[18]; b[17] = a[21]; b[18] = a[22]; b[22] = a[14]; b[21] = a[13];
    if (check()) {
        cout << "YES";
        return 0;
    }
    b[5] = a[13]; b[6] = a[14]; b[17] = a[5]; b[18] = a[6]; b[21] = a[17]; b[22] = a[18]; b[14] = a[22]; b[13] = a[21];
    if (check()) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}