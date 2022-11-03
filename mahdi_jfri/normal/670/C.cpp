#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
map<int , int> mp;
int b[maxn] , c[maxn] , res , node = -1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < m; i++)
        cin >> c[i];
    for(int i = 0; i < m; i++)
    {
        if(mp[b[i]] >= res)
        {
            if(node == -1 || mp[b[i]] > res)
            {
                node = i;
                res = mp[b[i]];
            }
            else if(mp[b[i]] == res && mp[c[i]] >= mp[c[node]])
                    node = i;
        }
    }
    cout << node + 1;
}