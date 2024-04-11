#include<bits/stdc++.h>
using namespace std;
long long int n,i,k,j,g=0,l;
long long int s[200005],a[200005];
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    s[0]=1;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++)
        {
            if(k*k>a[i])
            {
                break;
            }
        }
        k-=1;
        for(j=k;j>=1;j--)
        {
            if(a[i]%j==0)
            {
                if(j*j !=a[i] && a[i]/j<=200000)
                {s[a[i]/j]+=s[a[i]/j-1];
                s[a[i]/j]=s[a[i]/j]%1000000007;}
                s[j]+=s[j-1];
                s[j]=s[j]%1000000007;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        g+=s[i];
        g=g%1000000007;
    }
    cout<<g;
    return 0;
}