#include<bits/stdc++.h>
using namespace std;
long long n,i;
long long a[100010];

int main()
{
    cin>>n;
    if(n!=1)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        cout<<"1 1\n"<<-a[0]<<"\n";
        a[0]= 0;
        cout<<"2 "<<n<<endl;
        for(i=1;i<n;i++)
            cout<<(n-1)*a[i]<<' ',a[i] = n*a[i];
        cout<<endl;
        cout<<"1 "<<n<<endl;
        for(i=0;i<n;i++)
            cout<<-a[i]<<' ';
    }
    else
    {
        cin>>a[0];
        cout<<"1 1\n"<<-a[0]<<"\n";
        cout<<"1 1\n0\n";
        cout<<"1 1\n0\n";
    }
}