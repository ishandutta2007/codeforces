#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,m;
int pos;
long long t;

unordered_map<int, long long> mem[nmax];

int main()
{
    scanf("%i%i%i%lld",&n,&m,&pos,&t);

    int in=0;

    while(t)
    {
        in++;

        if(mem[t%n][pos])
        {
            t=t%(mem[t%n][pos]-t);
            break;
        }

        mem[t%n][pos]=t;

        if(pos<=m)
        {
            pos=(pos+t)%n;
            if(pos==0)pos=n;
        }
        else

        {
            pos=(pos-t)%n+n;
            if(pos>n)pos=pos-n;
        }

        t--;
    }

    while(t)
    {
        if(pos<=m)
        {
            pos=(pos+t)%n;
            if(pos==0)pos=n;
        }
        else

        {
            pos=(pos-t)%n+n;
            if(pos>n)pos=pos-n;
        }

        t--;
    }

    //cout<<in<<endl;

    printf("%i\n",pos);

    return 0;
}