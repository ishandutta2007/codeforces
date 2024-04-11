#include<bits/stdc++.h>
using namespace std;
int i,j,k,l,n,m,a,b,c,bit,checker=2,globtarget;
int mainlist[400005];
int bitlist[400005];
long long value = 0LL,counti = 0LL;
 
void createbit()
{
    for(k=0;k<n;k++)
        bitlist[k]=mainlist[k]%checker;
}
 
int bs(int mini, int maxi, int target)
{
    while(mini != maxi)
    {
        int med=(maxi+mini)/2;
        if(mini == maxi-1)
        {
            if(bitlist[maxi]>=target)
                mini=maxi;
            else maxi=mini;
        }
        else
        {
            if(bitlist[med]>=target)
                mini=med;
            else maxi=med;
        }
    }
    if(bitlist[0]>=target)
        return mini;
    else
        return -1;
}
 
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&mainlist[i]);
    }
    createbit();
    sort(bitlist,bitlist+n,greater<int>());
    for(j=0;j<n;j++)
    {
        globtarget=1-bitlist[j];
        a = bs(0,n-1,globtarget) +1;
        globtarget=2-bitlist[j];
        b = bs(0,a,globtarget) +1;
        globtarget=3-bitlist[j];
        c = bs(0,b,globtarget) +1;
        a=a-b+c;
        counti+=a;
    }
    value+=((counti/2)%2)*checker/2;
    checker = 4;
    for(i=1;i<26;i++)
    {
        counti=0;
        createbit();
        sort(bitlist,bitlist+n,greater<int>());
        for(j=0;j<n;j++)
        {
            globtarget=checker/2-bitlist[j];
            a = bs(0,n-1,globtarget) +1;
            globtarget=checker-bitlist[j];
            b = bs(0,a,globtarget) +1;
            globtarget=3*checker/2-bitlist[j];
            c = bs(0,b,globtarget) +1;
            a=a-b+c;
            counti+=a;
            if(bitlist[j]>=checker/4 && bitlist[j] < checker/2)
                counti--;
            if(bitlist[j]>=3*checker/4)
                counti--;
        }
        value+=((counti/2)%2)*checker/2;
        checker = checker*2;
    }
    printf("%lld",value);
    return 0;
}