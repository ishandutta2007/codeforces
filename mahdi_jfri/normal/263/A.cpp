#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int ii , jj , a;
int main()
{
    int n = 5;
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < n; j++)
        {
            cin >> a;
            if (a)
            {
                ii=i+1;
                jj=j+1;
            }
        }
    cout << abs(ii-3) + abs(jj-3);
}