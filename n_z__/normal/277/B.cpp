#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>=5&&m==3)return puts("-1"),0;
    for(int x=0;x<m;x++)
    cout<<x<<' '<<x*x<<endl;
    for(int x=0;x<n-m;x++)
    cout<<x*x+10000000<<' '<<x<<endl;
}