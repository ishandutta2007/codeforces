#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[200005],fv[5005];
vector <int> vv[5005];
char c[200005];
int main()
{
    long long i,j,mx=-999999999999LL,pz,n,k,cur=1,a,b,cnt=0;
    long long mn=-mx;
    cin>>n>>a>>b;
    if(a>b)
        cout<<n;
    else
    {
        for(i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(x<=a)
                ++cnt;
        }
        cout<<(cnt+1)/2;
    }
}