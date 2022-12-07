#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,Q,t,ans,rt;
int st[300010],top;
vector<int> v[300010];
int main()
{
    scanf("%d%d",&n,&Q);
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==1) t++,v[y].push_back(t),top++;
        else if(x==2)
        {
            for(int i=0;i<v[y].size();i++)
            {
                if(!st[v[y][i]]) ans++;
                st[v[y][i]]=1;
            }
            v[y].clear();
        }
        else
        {
            for(int i=rt+1;i<=y;i++)
            {
                if(!st[i]) ans++;
                st[i]=1;
            }
            rt=max(rt,y);
        }
        printf("%d\n",top-ans);
    }
    return 0;
}