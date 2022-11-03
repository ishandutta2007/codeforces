#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
const int inf = 1e8;
bool girl[maxn] , boy[maxn];
int x;
int main()
{
    int n , m , b , g;
    cin >> n >> m >> b;
    for(int i = 0; i < b; i++)
        cin >> x , boy[x] = 1;
    cin >> g;
    for(int i = 0; i < g; i++)
        cin >> x , girl[x] = 1;
    for(int i = 0; i < inf; i++)
    {
        int j = i % n;
        int jj = i % m;
        if(girl[jj] || boy[j])
        {
            boy[j] = girl[jj] = 1;
        }
    }
    for(int i = 0; i < n; i++)
        if(!boy[i])
        {
            cout << "No";
            return 0;
        }
    for(int i = 0; i < m; i++)
        if(!girl[i])
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
}