#include <bits/stdc++.h>
using namespace std;


int NOD(int x, int y)
    {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x == y) return x;
    if (x == 1 || y == 1) return 1;
    return NOD(x%y, y%x);
    }

long double x, y, X, Y;




int main()
    {
    //cout << NOD(3, 3);

    cin >> x >> y;

    X = log(x)*y;
    Y = log(y)*x;

    //cout << X << " " << Y << endl;


    if (X == Y)
        {
        cout << "=";
        return 0;
        }

    cout << ((X<Y)? "<":">");





    return 0;
    }