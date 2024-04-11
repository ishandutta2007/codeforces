#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


vector <int> q[2005];
int qu[2005];
int dist[2005];

int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        for (int j=0;j<m;j++)
        {
            scanf("%c",&c);
            if (c=='#')
            {
                q[i].push_back(n+j);
                q[n+j].push_back(i);
            }
        }
    }
    int fin=0;
    int st=n-1;
    dist[st]=1;
    int l=0;
    int r=1;
    qu[0]=st;
    while (l<r)
    {
        int cur=qu[l++];
        if (cur==fin)
        {
            printf("%d",dist[fin]-1);
            return 0;
        }
        int le=q[cur].size();
        for (int i=0;i<le;i++)
            if (!dist[q[cur][i]])
            {
                dist[q[cur][i]]=dist[cur]+1;
                qu[r++]=q[cur][i];
            }
    }
    printf("-1");

    

    return 0;
}