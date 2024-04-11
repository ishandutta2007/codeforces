#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
string s[maxn];
int a[maxn] , b[maxn] , c[maxn] , res = maxn * maxn, sum;
bool x1 , x2 , x3;
deque<pair<int , int> > v1 , v2 , v3;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        a[i] = b[i] = c[i] = maxn;
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&')
            {
                a[i] = min(a[i] , min(m - j , j));
            }
            if(s[i][j] >= '0' && s[i][j] <= '9')
            {
                b[i] = min(b[i] , min(m - j , j));
            }
            if(s[i][j] >= 'a' && s[i][j] <= 'z')
            {
                c[i] = min(c[i] , min(m - j , j));
            }
        }
        v1.pb({a[i] , i});
        v2.pb({b[i] , i});
        v3.pb({c[i] , i});
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int z = 0; z < n; z++)
            {
                if(a[i] == maxn || b[j] == maxn || c[z] == maxn)
                    continue;
                if(i == j || i == z || j == z)
                    continue;
                res = min(res , a[i] + b[j] + c[z]);
            }
    cout << res;
}