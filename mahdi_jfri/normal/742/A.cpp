#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[20];
int main()
{
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 1;
        return 0;
    }
    a[0] = 6;
    a[1] = 8;
    a[2] = 4;
    a[3] = 2;
    a[4] = 6;
    cout << a[n % 4];
}