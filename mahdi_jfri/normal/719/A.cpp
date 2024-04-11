#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int a[500];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n < 2 && a[n-1] != 0 && a[n-1] != 15)
    {
        cout << -1;
        return 0;
    }
    if((a[n-1] > a[n-2] && a[n-1] != 15) || (a[n-1] == 0))
        cout << "UP";
    else
        cout << "DOWN";
}