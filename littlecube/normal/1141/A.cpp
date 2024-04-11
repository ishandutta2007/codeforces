#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int a, b, two = 0, three = 0;
    cin >> a >> b;
    if (b % a)
    {
        cout << -1;
        return 0;
    }
    b /= a;
    while (b % 3 == 0)
    {
        three++;
        b /= 3;
    }
    while (b % 2 == 0)
    {
        two++;
        b /= 2;
    }
    if(b == 1){
        cout << two + three;
    }else{
        cout << -1;
    }
}