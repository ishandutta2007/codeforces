#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ma=0,s=0;
    for(int x=1,y;x<=n;x++)
    cin>>y,ma=max(ma,y),s+=y;
    cout<<2*ma-s+1;
}