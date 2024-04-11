/**"Sorry, but, even if you join us, there are 17 people."**/
#include<bits/stdc++.h>
using namespace std;
long long n,i,powe=1,j,k,total;
long long bits[500][61];
long long arr[500];

int main()
{
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    if(n<=3)
    {
        for(i=0;i<n;i++)
            total = total | arr[i];
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    long long cur = arr[i]|arr[j]|arr[k];
                    total = max(cur,total);
                }
            }
        }
    }
    cout<<total;
    return 0;
}