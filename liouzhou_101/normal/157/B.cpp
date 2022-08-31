#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

const int MaxN=110;
const long double Pi=3.1415926535897932384626;

int n;
int r[MaxN];

int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>r[i];
    sort(r+1,r+n+1);
    long double ans=0;
    for (int i=n;i>0;i-=2)
        ans+=Pi*(r[i]*r[i]-r[i-1]*r[i-1]);
    cout<<setprecision(15)<<fixed<<ans<<endl;
    return 0;
}