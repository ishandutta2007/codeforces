#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , x;
bool visited[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] , a[i]--;
    x = n - 1;
    for(int i = 0; i < n; i++)
    {
        visited[a[i]] = 1;
        while(visited[x] == 1 && x >= 0)
            cout << x + 1 << " " , x--;
        cout << endl;
    }
}