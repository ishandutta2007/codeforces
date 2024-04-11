#include <bits/stdc++.h>
using namespace std;

int Xp, Yp, Xv, Yv;

int main()
{
    cin >> Xp >> Yp >> Xv >> Yv;
    if (Xp+Yp <= max(Xv, Yv) || Xp <= Xv && Yp <= Yv) puts("Polycarp");
    else puts("Vasiliy");
}