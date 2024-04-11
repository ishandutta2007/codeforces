#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 4e5 + 20;
int a[6] , b[6] , res;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    for(int i = 1; i <= 5; i++)
    {
        if((a[i] + b[i]) & 1)
        {
            cout << -1;
            return 0;
        }
        res += abs(a[i] - (a[i] + b[i]) / 2);
    }
    cout << res / 2;
}