#include <bits/stdc++.h>
using namespace std;

int n, l1, r1, l2, r2, l3, r3;

int main() {
    cin >> n >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
    int n1 = n-l2-l3;
    if (n1 >= r1) n1 = r1;
    else if (n1 <= l1) n1 = l1;
    n -= n1;
    int n2 = n-l3;
    if (n2 >= r2) n2 = r2;
    else if (n2 <= l2) n2 = l2;
    n -= n2;
    cout << n1 << ' ' << n2 << ' ' << n << endl;
}