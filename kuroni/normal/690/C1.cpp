#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,u,v,lab[1001];
int getroot(int x)
{
    while (lab[x] > 0) x = lab[x];
    return x;
}
void Union(int r, int s)
{
    if (lab[r] < lab[s]) lab[s] = r;
    else
    {
    if (lab[r] == lab[s]) lab[s]--;
    lab[r] = s;
    }
}
int main()
{
    cin >> n >> m;
    if (n==m+1)
    {
    for (int i = 1; i<=m; i++)
    {
        cin>>x>>y;
        u = getroot(x);
        v = getroot(y);
        if (u!=v) Union(u,v);
        else {cout<<"no"<<endl; return 0;}
        }
        cout<<"yes"<<endl;
    }
        else cout<<"no"<<endl;
}