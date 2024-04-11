#include <bits/stdc++.h>
using namespace std;

unsigned long long n;

int main()
{
    cin >> n;
    n++;


    if (n == 1) cout << 0;

    else if((n/2)*2 != n) cout << n;


    else {n/= 2; cout << n;}


    return 0;
}