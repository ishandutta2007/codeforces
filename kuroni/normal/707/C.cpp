#include <bits/stdc++.h>
using namespace std;
main()
{
    long long n,a,b,i=0,t;
    cin>>n;
    t=n;
    while (t%2==0) {t/=2;i++;}
    if (t == 1)
    {
        if ((n == 1) || (n == 2)) cout<<-1;
        else {a = n/4*3; b = n/4*5; cout<<a<<" "<<b;}
    }
    else
    {
        t=t*t;
        t /= 2;
        a = t;
        b = t+1;
        while (i--) {a *= 2; b *= 2;}
        cout<<a<<" "<<b;
    }
}