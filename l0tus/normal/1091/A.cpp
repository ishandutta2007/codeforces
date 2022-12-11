#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;

int main()
{
    int y,b,r;
    cin >> y >> b >> r;
    cout << 3*min(min(y+2,b+1),r)-3;
}