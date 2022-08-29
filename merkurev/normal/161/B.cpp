#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> tab;
vector <pair<int,int>> kar;

void main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int k,n;
    scanf("%d%d",&n,&k);
    int type,price;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&price,&type);
        if (type==1)
            tab.push_back(make_pair(price,i+1));
        else
            kar.push_back(make_pair(price,i+1));
    }
    
    long long ans=0;
    int dif=k-tab.size();
    if (dif<=0)
    {
        sort(tab.begin(),tab.end());
        reverse(tab.begin(),tab.end());
        for (int i=0;i<min(k-1,int(tab.size()));i++)
        {
            ans+=tab[i].first;
        }
        for (int i=k-1;i<tab.size();i++)
        {
            kar.push_back(tab[i]);
        }
        sort(kar.begin(),kar.end());
        ans+=kar[0].first;
        for (int i=1;i<kar.size();i++)
            ans+=long long(kar[i].first)*2;



        printf("%I64d.",ans/long long(2));
        if (ans&long long(1))
            printf("5");
        else
            printf("0");
        printf("\n");


        for (int i=0;i<k-1;i++)
            printf("1 %d\n",tab[i].second);
        printf("%d",n-k+1);
        for (int i=0;i<n-k+1;i++)
            printf(" %d",kar[i].second);
    }
    else
    {
        for (int i=0;i<tab.size();i++)
            ans+=tab[i].first;
        for (int i=0;i<kar.size();i++)
            ans+=long long(kar[i].first)*2;

        printf("%I64d.",ans/long long(2));
        if (ans&long long(1))
            printf("5");
        else
            printf("0");
        printf("\n");

        for (int i=0;i<tab.size();i++)
            printf("1 %d\n",tab[i].second);
        for (int i=0;i<dif-1;i++)
        {
            printf("1 %d\n",kar[i].second);
        }
        printf("%d",kar.size()-dif+1);
        for (int i=dif-1;i<kar.size();i++)
            printf(" %d",kar[i].second);

    }
}