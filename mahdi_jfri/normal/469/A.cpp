#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e4 + 20;
bool visited[101];
int main()
{
    int n , p , q;
    cin >> n >> p;
    for(int i = 0; i < p; i++)
    {
        int a;
        cin >> a;
        visited[a - 1] = 1;
    }
    cin >> q;
    for(int i = 0;i < q; i++)
    {
        int a;
        cin >> a;
        visited[a - 1] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
}