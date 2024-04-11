#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res = 1;
int a[maxn];
int main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        if(k >= res)
            break;
        res *= 2;
        res += 1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(k > i + 1)
            k -= i + 1;
        else
        {
            cout << a[k - 1];
            return 0;
        }
    }
}