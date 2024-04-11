#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=1e3;
int visited[maxn];
int x[maxn],y[maxn];
int z;
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0; i < z; i++)
    {
        if(!visited[i] && i != v  && ((x[i] < x[v] && x[v] < y[i]) || (x[i] < y[v] && y[v] < y[i])))
            dfs(i);
    }
}
void sefrgaraei()
{
    for(int i = 0; i < z; i++)
        visited[i] = 0;
}
int a,b,c;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> x[z] >> y[z];
            z++;
        }
        else
        {
            cin >> b >> c;
            b--;
            c--;
            dfs(b);
            if(visited[c])
                cout << "YES\n";
            else
                cout << "NO\n";
            sefrgaraei();
        }
    }
}