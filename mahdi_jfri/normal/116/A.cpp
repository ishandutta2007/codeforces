#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+20;
int main()
{
    int n;
    cin>>n;
    int a,b;
    int cap=0;
    int _max=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cap-=a;
        cap+=b;
        _max=max(cap,_max);
    }
    cout<<_max;
}