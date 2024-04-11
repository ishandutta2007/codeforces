#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
int a[maxn] , x , b[maxn] , c[maxn] , n , l;
bool check()
{
    for(int i = 0; i < n; i++)
        if(b[i] != c[i])
            return 0;
    return 1;
}
int main()
{
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> a[i] , c[i] = a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[j]--;
            if(c[j] < 0)
                c[j] = l - 1;
        }
        sort(c , c + n);
        if(check())
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}