#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , b[maxn];
void check(int n)
{
    for(int i = 1; i < n; i++)
        if(i && a[i] && a[i - 1] && a[i] < a[i - 1])
        {
            cout << "Yes\n";
            exit(0);
        }
}
int main()
{
    int n , k;
    cin >> n >> k;
    if(k > 1)
    {
        cout << "Yes\n";
        return 0;
    }
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(!a[i])
            x = i;
    }
    int y;
    cin >> y;
    a[x] = y;
    check(n);
    cout << "No\n";
    return 0;
}