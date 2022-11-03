#include<bits/stdc++.h>
using namespace std;

long long a,b,c,n,i;
long long original[20];
long long check[20];

bool sorted(int aa)
{
    for(a=2;a<=aa;a++)
    {
        if(check[a]<check[a-1])
        {
            return false;
        }
    }
    return true;
}

int checked(int aa)
{
    int m,k;
    if(aa==1)
    {
        return 1;
    }
    if(sorted(aa))
    {
        return aa;
    } else
    {
        int checking[20];
        for(i=1;i<20;i++)
        {
            checking[i]=check[i];
        }
        for(i=1;i<=aa/2;i++)
        {
            check[i]=checking[i];
        }
        m = checked(aa/2);
        for(i=1;i<=aa/2;i++)
        {
            check[i]=checking[i+aa/2];
        }
        k = checked(aa/2);
        return max(m,k);
    }
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>check[i];
    }
    cout<<checked(n);
}