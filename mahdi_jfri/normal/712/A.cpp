#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int maxn=1e5+20;
ll b[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n-1;i++)
    {
        cout<<b[i]+b[i+1]<<" ";
    }
    cout<<b[n-1];
}