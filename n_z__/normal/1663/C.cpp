#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        s+=y;
    }
    cout<<s<<endl;
}