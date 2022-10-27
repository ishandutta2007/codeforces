#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "?";
    for(int i = 1; i <= 100; i++)
        cout << " " << i;
    cout << endl;
    cout.flush();
    int res1;
    cin >> res1;
    cout << "?";
    for(int i = 1; i <= 100; i++)
        cout << " " << (i << 7);
    cout << endl;
    cout.flush();
    int res2;
    cin >> res2;
    int x = 0;
    x |= (res1 & (((1 << 7) - 1) << 7));
    x |= (res2 & ((1 << 7) - 1));
    cout << "! " << x << endl;
    cout.flush();
    return 0;
}