
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n < 1200) cout << 1200;
    else if(n < 1400) cout << 1400;
    else if(n < 1600) cout << 1600;
    else if(n < 1900) cout << 1900;
    else if(n < 2100) cout << 2100;
    else if(n < 2300) cout << 2300;
    else if(n < 2400) cout << 2400;
    else if(n < 2600) cout << 2600;
    else cout << 3000;
}