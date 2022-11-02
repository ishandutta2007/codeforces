#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,s,m;
int a[2010];
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    k=n+1;
    cout<<n+1<<"\n";
    for(i=n;i>=1;i--)
    {
        s=a[i]%k;
        if(i-s>=0)
        {
            cout<<"1"<<" "<<i<<" "<<i-s<<"\n";
            for(j=1;j<=i;j++)
            {
                a[j]+=i-s;
            }
        }
        else
        {
            m=k+i-s;
            cout<<"1"<<" "<<i<<" "<<m<<"\n";
            for(j=1;j<=i;j++)
            {
                a[j]+=m;
            }
        }
    }
    cout<<"2 "<<n<<" "<<n+1;
    return 0;
}