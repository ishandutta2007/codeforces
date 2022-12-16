#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    long long s,n,k;

    scanf("%lld%lld%lld",&s,&n,&k);

    if(s<k)return 0;
    if(s==k)return 1;

    long long cnt_low=s%k+1;
    long long cnt_high=k-cnt_low;

    long long coeff_low=(s/k+2)/2;
    long long coeff_high=(s/k-1+2)/2;

    long long MX=cnt_low*coeff_low+cnt_high*coeff_high;

    /*
    long long actual_MX=0;
    for(int i=0;i<=k-1;i++)
        actual_MX+=((s-i)/k+2)/2;
    */

    //cout<<"MX= "<<MX<<endl;

    if(MX>=n+1)return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}