#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

long long n,inp[nmax];

long long modulo(long long x,long long y)
{
    x=x%y;
    x=(x+y)%y;

    return x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i];

    if(n==1)
    {
        for(int i=1;i<=3;i++)
        {
            cout<<1<<" "<<1<<endl;
            cout<<-inp[1]<<endl;
            inp[1]=0;
        }
        return 0;
    }

    cout<<1<<" "<<n<<endl;

    for(int i=1;i<=n;i++)
    {
        long long b=modulo(inp[i],(n-1));

        cout<<-n*b<<" ";

        inp[i]+=(-n*b);
    }
    cout<<endl;

    cout<<1<<" "<<n-1<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<-inp[i]<<" ";
        inp[i]=0;
    }
    cout<<endl;

    cout<<2<<" "<<n<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<-inp[i]<<" ";
        inp[i]=0;
    }
    cout<<endl;

    return 0;
}