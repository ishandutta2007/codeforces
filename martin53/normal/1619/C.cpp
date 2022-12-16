#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long a,s;

    scanf("%lld%lld",&a,&s);

    vector<int> ret={};

    while(s)
    {
        int cur=s%10-a%10;

        if(cur<0)cur+=10;

        if(a%10+cur<10)
        {
            a=a/10;
            ret.push_back(cur);
            s=s/10;
        }
        else
        {
            if(s%100!=a%10+cur)return -1;
            a=a/10;
            ret.push_back(cur);
            s=s/100;
        }
    }

    if(a)return -1;

    long long outp=0;
    for(int i=ret.size()-1;i>=0;i--)
        outp=outp*10+ret[i];

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }


    return 0;
}