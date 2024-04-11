#include <bits/stdc++.h>
using namespace std;

int u, v;

int main()
{
    cout << "? ";
    for (int i = 1; i <= 100; i++)
        cout << i << " ";
    cout << endl;
    cin >> u;
    cout << "? ";
    for (int i = 1; i <= 100; i++)
        cout << (i << 7) << " ";
    cout << endl;
    cin >> v;
    cout << "! " << (v ^ (((u ^ v) >> 7) << 7)) << endl;
}