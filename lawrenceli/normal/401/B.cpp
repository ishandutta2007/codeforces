#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 4005;

int x, k;
int arr[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> x >> k;
    arr[x] = 1;
    for (int i=0; i<k; i++) {
        int type; cin >> type;
        if (type == 1) {
            int num1, num2;
            cin >> num1 >> num2;
            arr[num1] = arr[num2] = 1;
        } else {
            int num; cin >> num;
            arr[num] = 1;
        }
    }

    int imin = 0, imax = 0, cur = 0;
    for (int i=1; i<=x; i++) {
        if (arr[i]) {
            if (cur) imin += (cur-1) / 2 + 1;
            imax += cur;
            cur = 0;
        } else cur++;
    }

    cout << imin << ' ' << imax << '\n';
    return 0;
}