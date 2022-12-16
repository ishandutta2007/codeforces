#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,a[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);

    int outp=n-1;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int cur_correct=0;

            for(int k=1;k<=n;k++)
                if(k==i)cur_correct++;
                else if((a[j]-a[i])*(k-i)%(j-i)==0&&a[i]+(a[j]-a[i])*(k-i)/(j-i)==a[k])cur_correct++;

            //cout<<i<<" "<<j<<" -> "<<cur_correct<<endl;

            outp=min(outp,n-cur_correct);
        }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}