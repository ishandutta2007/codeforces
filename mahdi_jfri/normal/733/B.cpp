#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 20;
int l[maxn] , r[maxn];
ll _max , riight , leeft;
ll res , javab = -1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        leeft += l[i];
        riight += r[i];
    }
    res = abs(leeft - riight);
    for(int i = 0; i < n; i++)
    {
        leeft -= l[i];
        leeft += r[i];
        riight -= r[i];
        riight += l[i];
        if(abs(leeft - riight) > res)
        {
            javab = i;
            res = abs(leeft - riight);
        }
        leeft = leeft - r[i] + l[i];
        riight = riight - l[i] + r[i];
    }
    if(javab == -1)
        cout << 0;
    else
        cout << javab + 1;
}