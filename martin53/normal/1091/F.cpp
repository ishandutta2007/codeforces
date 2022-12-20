#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
long long inp[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    long long outp=0,extra_grass=0,total_water=0,stamina=0;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        if(c=='G')
        {
            outp+=5*inp[i];

            stamina+=inp[i];

            extra_grass+=2*inp[i];
        }
        if(c=='W')
        {
            outp+=3*inp[i];

            stamina+=inp[i];

            total_water+=inp[i];
        }

        if(c=='L')
        {
            long long extra=max(0LL,inp[i]-stamina);

            outp+=inp[i];

            stamina-=inp[i];

            stamina+=extra;
            if(total_water)outp+=3*extra;
            else outp+=5*extra;
        }

        extra_grass=min(extra_grass,stamina);
    }

    //cout<<outp<<" "<<stamina<<" "<<extra_grass<<endl;

    long long save_grass=min((5-1)*stamina/2,(5-1)*extra_grass/2);

    outp-=save_grass;

    stamina-=save_grass/2;

    //cout<<"save_grass= "<<save_grass<<endl;

    long long save_water=(3-1)*stamina/2;

    outp-=save_water;

    //cout<<"stamina= "<<stamina<<endl;

    printf("%lld\n",outp);
    return 0;
}