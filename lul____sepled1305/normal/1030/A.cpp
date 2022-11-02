#include<bits/stdc++.h>
using namespace std;
int n,i,j=0,m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>m;
        j+=m;
    }
    if(j==0)
    {
        cout<<"EASY";
    }
    else
    {
        cout<<"HARD";
    }
    return 0;
}