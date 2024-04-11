#include<bits/stdc++.h>
using namespace std;
long int n,k,i,g,h;
int main(){
    scanf("%d%d",&n,&k);
    long int a[n+1],b[200001],c[200001];
    for(i=1;i<=200000;i++)
    {
        c[i]=0;
        b[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[a[i]]++;
        b[a[i]]++;
    }
    sort(b+1,b+200001);
    long long int sum=0;;
    for(g=1;g<=200000;g++)
    {
        sum=0;
        for(i=200001-k;i<=200001;i++)
        {
            sum+=b[i]/g;
        }
        if(sum<k)
        {
            break;
        }
    }
    g=g-1;
    if(g==199999)
    {
        for(i=200001-k;i<=200001;i++)
        {
            sum+=b[i]/200000;
        }
        if(sum>=k)
        {
            g=200000;
        }
    }
    sum=0;
    if(g>0)
    for(i=1;i<=200000;i++)
    {
        for(h=1;h<=c[i]/g;h++)
        {
            sum++;
            if(sum<=k)
            {
                printf("%d ",i);
            }
        }
    }
    else
    {
        for(i=1;i<=k;i++)
        {
            printf("1 ");
        }
    }
}