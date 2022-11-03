#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e4 + 20;
ll res , u;
int main()
{
    int a , b;
    cin >> a >> b;
    while(a)
    {
        res += a;
        u += a;
        a = 0;
        a += u / b;
        u %= b;
    }
    cout << res;
}