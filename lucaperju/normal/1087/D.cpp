#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int v[100005];
int main()
{
    int n,s,a,b,i,cnt=0;
    cin>>n>>s;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        ++v[a];
        ++v[b];
    }
    for(i=1;i<=n;++i)
        if(v[i]==1)
            ++cnt;
    double rez;
    rez=s*2.0;
    rez=rez/cnt;
    cout<<fixed<<setprecision(10)<<rez;
}