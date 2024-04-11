#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
int main()
{
    int a , b , s;
    cin >> a >> b >> s;
    a = abs(a);
    b = abs(b);
    s -= (a + b);
    if(s % 2 == 0 && s >= 0)
        cout << "YES";
    else
        cout << "NO";
}