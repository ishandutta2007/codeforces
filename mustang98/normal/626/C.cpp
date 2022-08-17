#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll dif,n,m,max2,max3,kr;
    cin>>n>>m;
    max2=n*2;
    max3=m*3;
    kr=min(max2,max3)/6;
    /*ll kol;
    if (max2<max3)
    {
        dif = max3-max2;
        kol = dif/2;
        kol = min(kol,kr);
        max2+=2*kol;
        kr-=kol;
    }
    else if (max2>max3)
    {
        dif = max2-max3;
        kol = dif/3;
        kol = min(kol,kr);
        max3+=3*kol;
        kr-=kol;
    }*/
    while(kr)
    {
       if (max2==max3)
       {
           max2+=2;
           kr--;
           continue;
       }
       if (max2<max3)
       {
           max2+=2;
           if (max2%6==0 && max2<=max3) continue;
           kr--;
           continue;
       }
       max3+=3;
       if (max3%6==0 && max3<=max2) continue;
       kr--;
    }
    cout<<max(max2,max3);
    return 0;
}