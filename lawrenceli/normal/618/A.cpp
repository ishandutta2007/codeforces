#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;

int n;
int ar[maxn], sze;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ar[sze++] = 1;
        while (sze > 1 && ar[sze - 1] == ar[sze - 2])
            ar[sze - 2]++, sze--;
    }

    for (int i = 0; i < sze; i++) cout << ar[i] << ' ';
}