#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const double pi = acos(-1);
double d , h , v , e;
int main()
{
    cin >> d >> h >> v >> e;
    d /= 2;
    double now = d * d * pi * h , inc = e , dec = v / (d * d * pi);
    if(dec <= inc)
    {
        if(dec == inc && now == 0)
        {
            cout << "YES\n0";
            return 0;
        }
        cout << "NO";
        return 0;
    }
    cout << fixed << setprecision(20);
    cout << "YES\n" << (h) / (dec - inc);
}