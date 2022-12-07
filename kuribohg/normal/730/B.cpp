#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int T,n;
vector<int> winner,loser;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        winner.clear();
        loser.clear();
        scanf("%d",&n);
        for(int i=1;i+1<=n;i+=2)
        {
            printf("? %d %d\n",i,i+1);
            fflush(stdout);
            char str[10];
            scanf("%s",str);
            if(str[0]=='<') winner.push_back(i+1),loser.push_back(i);
            else if(str[0]=='>') winner.push_back(i),loser.push_back(i+1);
            else winner.push_back(i),loser.push_back(i+1);
        }
        if(n%2==1) winner.push_back(n),loser.push_back(n);
        int cur=0;
        for(int i=1;i<winner.size();i++)
        {
            printf("? %d %d\n",winner[cur],winner[i]);
            fflush(stdout);
            char str[10];
            scanf("%s",str);
            if(str[0]=='<') cur=i;
        }
        int Max=winner[cur];
        cur=0;
        for(int i=1;i<loser.size();i++)
        {
            printf("? %d %d\n",loser[cur],loser[i]);
            fflush(stdout);
            char str[10];
            scanf("%s",str);
            if(str[0]=='>') cur=i;
        }
        int Min=loser[cur];
        printf("! %d %d\n",Min,Max);
        fflush(stdout);
    }
    return 0;
}