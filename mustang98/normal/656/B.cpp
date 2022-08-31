#include <iostream>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    long double res=0;
    cin>>n;
    int m[16];
    int r[16];
    int a[1000000]={0};
    for (int i=0;i<n;i++) cin>>m[i];
    for (int i=0;i<n;i++) cin>>r[i];
    for (int i=0;i<1000000;i++)
    {
        for(int j=0;j<n;j++) if (m[j]>0 && i%m[j]==r[j]) {a[i]=1; break;}
    }
    int ans=0;
    for (int i=0;i<1000000;i++) ans+=a[i];
    long double l = (double)ans/(double)1000000;
    cout.precision(10);
    cout<<l;
    return 0;
}