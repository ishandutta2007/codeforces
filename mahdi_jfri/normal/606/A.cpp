#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int a , b , c;
int main()
{
    int x1 , x2 , x3;
    cin >> x1 >> x2 >> x3;
    cin >> a >> b >> c;
    ll sum = 0;
    if(x1 < a)
        sum += (x1 - a);
    else
        sum += (x1 - a) / 2;
    if(x2 < b)
        sum += (x2 - b);
    else
        sum += (x2 - b) / 2;
    if(x3 < c)
        sum += (x3 - c);
    else
        sum += (x3 - c) / 2;
    if(sum >= 0)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}