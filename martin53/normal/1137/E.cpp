#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,off=1e9;

int n,q;

int l,r;

pair<long long,int> active[nmax];
int pointer;

pair<long long,int> meet(pair<long long,int> a,pair<long long,int> b)
{
    return {a.first-b.first,b.second-a.second};
}
bool check(pair<long long,int> one,pair<long long,int> two,pair<long long,int> three)
{
    pair<long long,int> high=meet(one,two);

    pair<long long,int> low=meet(two,three);

    //cout<<"check "<<one.first<<" "<<one.second<<" "<<two.first<<" "<<two.second<<" "<<three.first<<" "<<three.second<<" -> "<<low.first<<" "<<low.second<<" "<<high.first<<" "<<high.second<<" : "<<(low.first*high.second<low.second*high.first)<<endl;

    return low.first*high.second<low.second*high.first;
}
int main()
{
    scanf("%i%i",&r,&q);

    r=r+off;
    l=1+off;

    pointer=1;
    active[pointer]={0,l};

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==1)
        {
            int k;
            scanf("%i",&k);

            l=l-k;

            pointer=1;
            active[pointer]={0,l};
        }
        else if(type==2)
        {
            int k;
            scanf("%i",&k);

            r=r+k;

            if(pointer&&active[pointer].first!=0)
            {
                while(pointer>=2&&check(active[pointer-1],active[pointer],{0,r-k+1})==0)pointer--;

                pointer++;
                active[pointer]={0,r-k+1};
            }
        }
        else
        {
            int b,s;

            scanf("%i%i",&b,&s);

            for(int j=1;j<=pointer;j++)
                active[j].first+=(b+1LL*(active[j].second-l)*s);
        }

        while(pointer>=2&&active[pointer].first>=active[pointer-1].first)pointer--;

        /*
        for(int j=1;j<=pointer;j++)
            cout<<j<<" -> "<<active[j].first<<" "<<active[j].second<<endl;
        */

        printf("%i %lld\n",active[pointer].second+1-l,active[pointer].first);
    }
    return 0;
}