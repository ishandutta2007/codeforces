#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

bool prime[nmax];//1->prime

bool good[nmax];

int pref[nmax];

int solve()
{
    scanf("%i",&n);

    if(n<=3)return n;

    /*
    for(int i=1;i<=n;i++)
        good[i]=0;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int a=__gcd(i,j);
            int b=i/a;
            int c=j/a;

            if(a+b>c&&b+c>a&&c+a>b)
            {
                good[i]=1;
                good[j]=1;
            }
        }

    int cnt=0;
    for(int i=1;i<=n;i++)
        if(good[i]==0)
        {
            cout<<i<<" ";
            cnt++;
        }

    cout<<endl;
    */

    int k=sqrt(n+1);

    while(k*k<n+1)k++;

    int ret=1+pref[n]-pref[k-1];

    //cout<<"ret= "<<ret<<" k= "<<k<<endl;

    //assert(cnt==ret);

    return ret;
}

int main()
{
    for(int i=1;i<nmax;i++)
        prime[i]=1;

    prime[1]=0;

    for(int i=2;i<nmax;i++)
        if(prime[i])
        {
            for(long long j=1LL*i*i;j<nmax;j=j+i)
                prime[j]=0;
        }

    for(int i=1;i<nmax;i++)
        pref[i]=pref[i-1]+prime[i];

    int t;
    scanf("%i",&t);

    while(t)
    {
        printf("%i\n",solve());
        t--;
    }

    return 0;
}