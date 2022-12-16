#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,inp[nmax];
int pref[nmax],suff[nmax];
int order[nmax],which[nmax];
int help[nmax];
mt19937 rng(time(0));
int main()
{
    //srand(time(0));
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    map<int,int> s={};
    int n_=0;
    for(int i=1;i<=n;i++)
    {
        if(s[inp[i]]<2)
        {
            n_++;
            help[n_]=inp[i];
            order[n_]=i;
            s[inp[i]]++;
        }
    }

    int t=clock();
    while(1.0*(clock()-t)/CLOCKS_PER_SEC<0.4)
    {
        //shuffle(order+1,order+n+1,rng());
        for(int i=1;i<=n_;i++)
            swap(order[i],order[rng()%n_+1]);

        pref[1]=inp[order[1]];
        for(int i=2;i<=n_;i++)
            pref[i]=__gcd(pref[i-1],inp[order[i]]);

        suff[n_]=inp[order[n_]];
        for(int i=n_-1;i>=1;i--)
            suff[i]=__gcd(suff[i+1],inp[order[i]]);

        for(int i=1;i<n_;i++)
            if(pref[i]==1&&suff[i+1]==1)
            {
                for(int j=1;j<=n;j++)
                    which[j]=2;
                for(int j=1;j<=i;j++)
                    which[order[j]]=1;

                printf("YES\n");
                for(int j=1;j<=n;j++)
                    printf("%i ",which[j]);
                return 0;
            }
    }
    printf("NO\n");
    return 0;
}