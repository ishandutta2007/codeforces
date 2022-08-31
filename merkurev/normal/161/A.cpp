#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> ans;
int s[100500];
int b[100500];


void main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for (int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for (int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int curS=0;
    int curB=0;
    while (curS<n && curB<m)
    {
        int lg=s[curS]-x;
        int rg=s[curS]+y;
        int br=b[curB];
        if (lg<=br && br<=rg)
        {
            curS++;
            curB++;
            ans.push_back(make_pair(curS,curB));
            continue;
        }
        if (br<lg)
        {
            curB++;
            continue;
        }
        if (br>rg)
        {
            curS++;
            continue;
        }
    }
    printf("%d",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("\n%d %d",ans[i].first,ans[i].second);

}