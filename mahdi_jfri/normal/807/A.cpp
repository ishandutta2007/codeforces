#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , b[maxn] , t[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if(b[i] != a[i])
        {
            cout << "rated";
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] < a[i + 1])
        {
            cout << "unrated";
            return 0;
        }
    }
    cout << "maybe";
}