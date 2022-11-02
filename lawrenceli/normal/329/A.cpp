#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n;
bool evil[MAXN][MAXN];
bool revil, cevil;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char c;
            cin >> c;
            if (c=='.') evil[i][j]=0;
            else evil[i][j]=1;
        }
    }
    for (int i=0; i<n; i++) {
        bool b=1;
        for (int j=0; j<n; j++) {
            if (!evil[i][j]) {
                b=0;
                break;
            }
        }
        if (b) revil=1;
    }
    for (int j=0; j<n; j++) {
        bool b=1;
        for (int i=0; i<n; i++) {
            if (!evil[i][j]) {
                b=0;
                break;
            }
        }
        if (b) cevil=1;
    }
    if (revil && cevil) {
        cout << -1 << endl;
        return 0;
    }
    if (revil) {
        for (int j=0; j<n; j++) {
            for (int i=0; i<n; i++) {
                if (!evil[i][j]) {
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!evil[i][j]) {
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }
            }
        }
    }
}