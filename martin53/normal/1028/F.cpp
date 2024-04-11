#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n;

void compress(int &x,int &y)
{
    int g=__gcd(x,y);

    x=x/g;
    y=y/g;
}

map< pair<int,int>,int > points,line;

map< long long, set< pair<int,int> > > mem;

int main()
{
    int active=0;

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int type,x,y;
        scanf("%i%i%i",&type,&x,&y);

        if(type==3)
        {
            compress(x,y);

            //cout<<"active= "<<active<<endl;

            printf("%i\n",active-points[{x,y}]-2*line[{x,y}]);
        }
        if(type==1)
        {
            active++;

            int x_=x,y_=y;

            compress(x_,y_);

            points[{x_,y_}]++;

            long long d=1LL*x*x+1LL*y*y;

            for(auto p:mem[d])
            {
                int x_help=x+p.first,y_help=y+p.second;

                compress(x_help,y_help);

                line[{x_help,y_help}]++;
            }

            mem[d].insert({x,y});
        }

        if(type==2)
        {
            active--;

            int x_=x,y_=y;

            compress(x_,y_);

            points[{x_,y_}]--;

            long long d=1LL*x*x+1LL*y*y;

            mem[d].erase({x,y});

            for(auto p:mem[d])
            {
                int x_help=x+p.first,y_help=y+p.second;

                compress(x_help,y_help);

                line[{x_help,y_help}]--;
            }
        }
    }
    return 0;
}