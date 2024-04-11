#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
ll a[3],m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i < 3 ; i++)
        for(int j =0 ; j < n-i ; j++)
        {
            cin >> m;
            a[i]+=m;
        }
    cout << a[0] - a[1] << endl << a[1] - a[2];
}