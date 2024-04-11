#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double a[100 + 10];

int main()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++ ) 
        cin >> a[i];
    sort( a, a + n ) ; 

    if( a[ n - 1 ] >= 0.5 ) 
    {
        cout << a[n-1] << endl;
        return 0;
    }

    double b = a[n-1];
    double p = 1 - a[n-1];

    for(int i = n - 2 ; i >= 0 ; i-- ) 
    {
        double nb= b*(1-a[i]) + p*a[i], np = p*(1-a[i]);
        if( b < nb ) 
            b = nb, p = np;
    }
    cout << fixed << setprecision(9) << b << endl;
}