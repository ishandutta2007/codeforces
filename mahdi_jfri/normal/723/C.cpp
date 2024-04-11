#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn];
stack<int> st[maxn];
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > m)
            st[m + 1].push(i);
        else
            st[a[i]].push(i);
    }
    for(int i = 1; i <= m; i++)
        while(st[i].size() > n / m)
            st[m + 1].push(st[i].top()) , st[i].pop();
    ll x = 0;
    for(int i = 1; i <= m; i++)
        while(st[i].size() < n / m)
            st[i].push(st[m + 1].top()) , st[m + 1].pop() , a[st[i].top()] = i , x++;
    cout << n / m << " " << x << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}