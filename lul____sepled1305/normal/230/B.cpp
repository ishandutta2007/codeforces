#include<bits/stdc++.h>
using namespace std;
long long t,a,b,i,j;
bool prime[1000020];

int main()
{
    cin>>t;
    for(i=2;i<1000010;i++)
    {
        if(!prime[i])
        {
            for(j = i*i; j<1000010;j+=i)
            {
                prime[j] = true;
            }
        }
    }
    while(t--)
    {
        cin>>a;
        if(a == floor(sqrt(a)) * floor(sqrt(a)) && a!=1)
        {
            if(!prime[(int) floor(sqrt(a))])
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}