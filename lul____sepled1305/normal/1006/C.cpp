#include<bits/stdc++.h>
using namespace std;
long long int i=1,j,n,f=0,s1=0,s2=0,sum=0;
long long int a[200010];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    i=0;
    j=n+1;
    while(i<j)
    {
        if(s1<s2)
        {
            i++;
            s1+=a[i];
        }
        else if(s2<s1)
        {
            j--;
            s2+=a[j];
        }
        else if(s2==s1)
        {
            f=i;
            i++;
            s1+=a[i];
        }
    }
    for(i=1;i<=f;i++)
        sum+=a[i];
    cout<<sum;
}