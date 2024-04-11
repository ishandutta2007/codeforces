#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 20;
int a[maxn] , res = 1 , _max = 1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[i - 1])
            res++;
        else
        {
            _max = max(res , _max);
            res = 1;
        }
    }
    cout << _max;
}