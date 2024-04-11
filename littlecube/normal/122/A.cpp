#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{

    int n;
    cin >> n;
    cout << ((n % 4 && n % 7 && n % 44 && n % 47 && n % 74 && n % 77 && n % 444 && n % 447 && n % 474 && n % 477 && n % 744 && n % 747 && n % 774 && n % 777) ? "NO\n" : "YES\n");
}