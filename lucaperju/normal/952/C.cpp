#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int v[15];
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(i>=2 && (v[i]-v[i-1]>=2 || v[i-1]-v[i]>=2))
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}