#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll p(int b)
{
    ll rez=1;
    for(int i=0;i<b;i++) rez*=2;
    return rez;
}
int m[8];
int main()
{
    ll r,n,R,fl=0;
    cin>>n;
    r=n*(n-1)*(n-2)*(n-3)*(n-4);
    r/=120;
    R=r;
    r=n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5);
    r/=720;
    R+=r;
    r=1;
    for(int i=0;i<7;i++)
    {
        r*=(n-i);
        for (int j=2;j<=7;j++)
            if (r%j==0 && m[j]==0)
        {
            m[j]=1;
            r/=j;
        }
    }
    R+=r;
    cout<<R;
    return 0;
}