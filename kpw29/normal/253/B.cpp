#include <bits/stdc++.h>
using namespace std;

int c[5005],a[5005],postsum[5005],presum[5005];
int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int Min,n,x,l=0;
    cin>>n;
    Min=n;
    while(n--)
    {
        cin>>x;
        c[x]++;
    }
    for(int i=1;i<=5000;i++)
        if(c[i])
            a[l++]=i;

    for(int i=5000;i>=1;i--)
        postsum[i]=postsum[i+1]+c[i];
    for(int i=1;i<=5000;i++)
        presum[i]=presum[i-1]+c[i];
    for(int i=0;i<l;i++)
    {
        if(a[i]<2500 && Min>presum[a[i]-1]+postsum[2*a[i]+1])
            Min=presum[a[i]-1]+postsum[2*a[i]+1];
        else if(a[i]>=2500 && Min>presum[a[i]-1])
            Min=presum[a[i]-1];
    }
    cout<<Min<<'\n';

    return 0;
}