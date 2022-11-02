#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int r, c;
bool good[15][15];
char cake[15][15];

int main() {
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> cake[i][j];
        }
    }
    for (int i=0; i<r; i++) {
        bool b = 1;
        for (int j=0; j<c; j++) {
            if (cake[i][j]=='S') b=0;
        }
        if (!b) continue;
        for (int j=0; j<c; j++) good[i][j]=1;
    }
    for (int j=0; j<c; j++) {
        bool b = 1;
        for (int i=0; i<r; i++) {
            if (cake[i][j]=='S') b=0;
        }
        if (!b) continue;
        for (int i=0; i<r; i++) good[i][j]=1;
    }
    int tot=0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            tot+=good[i][j];
        }
    }
    cout << tot << endl;
}