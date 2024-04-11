#include<bits/stdc++.h>
using namespace std;
int n,i;

int main()
{
    cin>>n;
    cout<<4+3*n<<"\n";
    cout<<"0 0\n";
    for(i=0;i<=n;i++)
    {
        cout<<i<<" "<<i+1<<"\n";
        cout<<i+1<<" "<<i<<"\n";
        cout<<i+1<<" "<<i+1<<"\n";
    }
    return 0;
}