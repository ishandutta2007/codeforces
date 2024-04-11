#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap (a,b);
    }
    return a;
}

int main()
{
    int n,a;
    int kol[55];
    int R[55]={0};
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int o=1;o<=n;o++) kol[o]=0;
        for (int j=1;j<=n;j++)
        {
            cin>>a;
            kol[a]++;
        }
        for (int ch=1;ch<=n;ch++)
        if (kol[ch]>1) {R[i]=ch; break;}
    }
    for (int i=1;i<=n;i++) if (R[i]==0) {R[i]=n; break;}
    for (int i=1;i<=n;i++) if (R[i]==0) R[i]=n-1;
    for (int i=1;i<=n;i++) cout<<R[i]<<' ';

    return 0;
}