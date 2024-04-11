#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;
long long l,r;

vector<int> divs[nmax];

bool solve(int x1)
{
    long long low_y1=(l+x1-1)/x1;

    long long high_y1=r/x1;

    if(high_y1>=m)high_y1=m;

    if(low_y1>high_y1)return 0;

    for(auto g:divs[x1])
    {
        int x1_prime=x1/g;

        if(x1_prime+1>n/g)continue;

        int ok=1+x1_prime;

        while(ok<=n/g)
        {
            int not_ok=n/g+1;

            if(high_y1/ok!=(low_y1-1)/ok)
            {
                int x2_prime=ok;

                int x2=g*x2_prime;

                int y1=(high_y1/x2_prime)*x2_prime;

                int y2=1LL*x1*y1/x2;

                //cout<<low_y1<<" "<<high_y1<<" -> "<<x1_prime<<" "<<x2_prime<<" "<<g<<endl;

                printf("%i %i %i %i\n",x1,y1,x2,y2);
                return 1;
            }

            while(not_ok-ok>1)
            {
                int x2_prime=(ok+not_ok)/2;

                if(high_y1/x2_prime!=(low_y1-1)/x2_prime)
                {
                    int x2=g*x2_prime;

                    int y1=(high_y1/x2_prime)*x2_prime;

                    int y2=1LL*x1*y1/x2;

                    //cout<<low_y1<<" "<<high_y1<<" -> "<<x1_prime<<" "<<x2_prime<<" "<<g<<endl;

                    printf("%i %i %i %i\n",x1,y1,x2,y2);
                    return 1;
                }
                else if(high_y1/ok==high_y1/x2_prime)ok=x2_prime;
                else not_ok=x2_prime;
            }

            ok=not_ok+1;
        }
        /*
        for(int x2_prime=x1_prime+1;x2_prime<=n/g;x2_prime++)
            if(high_y1/x2_prime!=(low_y1-1)/x2_prime)
            {
                int x2=g*x2_prime;

                int y1=(high_y1/x2_prime)*x2_prime;

                int y2=1LL*x1*y1/x2;

                //cout<<low_y1<<" "<<high_y1<<" -> "<<x1_prime<<" "<<x2_prime<<" "<<g<<endl;

                printf("%i %i %i %i\n",x1,y1,x2,y2);
                return 1;
            }
        */
    }
    return 0;
}
int main()
{
    scanf("%i%i%lld%lld",&n,&m,&l,&r);

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j=j+i)
            divs[j].push_back(i);

    for(int x1=1;x1<=n;x1++)
    {
        if(solve(x1)==0)
        {
            printf("-1\n");
        }
    }

    return 0;
}