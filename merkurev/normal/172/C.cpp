#include <iostream>
#include <algorithm>

using namespace std;

int ans[100500];
pair<int,int> pos[100500];


void main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    int curtime=0;
    for (int i=0;i<n;i++)
    {
        int t,x;
        scanf("%d%d",&t,&x);
        pos[i%m]=make_pair(x,i);
        curtime=max(curtime,t);
        int anstime=curtime;
        if (i%m==m-1 || i==n-1)
        {
            int men=i%m+1;
            sort(pos,pos+men);
            int curx=0;
            int curnum=0;
            for (int j=0;j<men;j++)
            {
                if (curx==pos[j].first)
                {
                    if (curnum&1)
                    {
                        curtime++;
                    }
                    curnum++;
                    ans[pos[j].second]=anstime;
                }
                else
                {
                    curtime+=pos[j].first-curx;
                    anstime=curtime;
                    ans[pos[j].second]=anstime;
                    curx=pos[j].first;
                    curnum=1;
                    curtime++;
                }
            }
            curtime+=pos[men-1].first;
        }
    }
    for (int i=0;i<n;i++)
        printf("%d ",ans[i]);


}