#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , b[maxn] , c[maxn] , n;
vector<int> v , v1;
bool x[maxn] , y[maxn];
bool d(int a[maxn] , int b[maxn] , int n)
{
    int res = 0;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            res++;
    return res == 1;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i])
            c[i] = a[i] , x[a[i]] = 1 , y[a[i]] = 1;
        else
            v.pb(i);
    }
    v1 = v;
    for(int i = 1; i <= n; i++)
        if(!x[i])
            c[v.back()] = i , v.pop_back();
    if(d(a , c , n) && d(b , c , n))
    {
        for(int i = 0; i < n; i++)
            cout << c[i] << " ";
        return 0;
    }
    for(int i = n; i >= 1; i--)
    {
        if(!y[i])
            c[v1.back()] = i , v1.pop_back();
    }
    for(int i = 0; i < n; i++)
        cout << c[i] << " ";
}