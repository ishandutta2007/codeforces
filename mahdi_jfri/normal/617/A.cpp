#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int a[6] = {1, 2, 3, 4, 5} , res;
int main()
{
    int x;
    cin >> x;
    int i = 4;
    while(x)
    {
        if(x >= a[i])
            x -= a[i] , res++;
        else
            i--;
    }
    cout << res;
}