/*Ithea love implementation problem*/
#include<bits/stdc++.h>
using namespace std;
const int INF = -1e9;
int n,i,j;
long long maxi=0;
 
int main()
{
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<=30;i++)
    {
        long long sum=0,local_maxi=0;
        bool pass = false;
        for(j=0;j<n;j++)
        {
            if(a[j] == i)
                pass = true;
            if(a[j]>i)
                sum += INF;
            else
                sum+=a[j];
            if(sum < 0)
                sum = 0;
            if(sum > local_maxi)
                local_maxi = sum;
        }
        if(pass && local_maxi - i > maxi)
            maxi = local_maxi - i;
    }
    cout<<maxi;
}