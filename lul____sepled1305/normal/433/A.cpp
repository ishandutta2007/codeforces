#include<bits/stdc++.h>
using namespace std;

long long n,m,i,j,k,a,b,c,sum;
long long apple[105];

int main()
{
    bool R = false;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>apple[i];
        apple[i]/=100;
        if(apple[i]==1)
        {
            R = true;
        }
        sum+=apple[i];
    }
    if(sum%4==0)
    {
        cout<<"YES";
    } else if (sum%2==0 && R)
    {
        cout<<"YES";
    } else
    {
        cout<<"NO";
    }
    return 0;
}