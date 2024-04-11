#include<bits/stdc++.h>
using namespace std;
const int nmax=2e2+5;
int n;
vector< int > seen[nmax*nmax/2];
vector< int > there[nmax];
bool printed[nmax];
int cnt[nmax];
int main()
{
scanf("%i",&n);

int k,x;
for(int i=1;i<=n*(n-1)/2;i++)
{
    scanf("%i",&k);
    for(int j=1;j<=k;j++)
    {
        scanf("%i",&x);
        seen[i].push_back(x);
    }
    for(auto k:seen[i])
        there[k].push_back(i);
}

if(n==2)
{
    int i;
    for(i=1;i<nmax;i++)
        if(there[i].size())
        {
            printf("%i %i\n",1,i);
            break;
        }

    printf("%i",seen[1].size()-1);
    for(i=i+1;i<nmax;i++)
        if(there[i].size())
        {
            printf(" %i",i);

        }
    printf("\n");
    return 0;
}

for(int i=1;i<nmax;i++)
    if(printed[i]==0&&there[i].size())
    {
        memset(cnt,0,sizeof(cnt));
        for(auto ind:there[i])
            for(auto value:seen[ind])
                cnt[value]++;
        vector<int> now={};
        for(int j=1;j<nmax;j++)
            if(cnt[j]==there[i].size())now.push_back(j);
        printf("%i",now.size());for(auto k:now)printf(" %i",k);printf("\n");
        for(auto k:now)
            printed[k]=1;
    }

return 0;
}