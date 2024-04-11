#include <bits/stdc++.h>
using namespace std;

int n,sum,cnt,x;
char s[105],g[105];
pair<int, int> r[105];
queue<int> mq;
bool ch;

int main()
{
    scanf("%d",&n);
    memset(s,'0',sizeof(s));
    memset(g,'0',sizeof(g));
    s[n]='\0';
    g[n]='\0';
    for(int i=0;i<n;i++)
    {
        scanf("%d",&r[i].first);
        sum+=r[i].first;
        r[i].second=i;
    }
    sort(r,r+n);
    while(r[0].first!=r[n-1].first)
    {
        cnt++;
        if(r[n-1].first==r[0].first+1&&sum-n*r[0].first==3)
        {
            ch=true;
            g[r[n-1].second]='1';
            g[r[n-2].second]='1';
            g[r[n-3].second]='1';
            break;
        }
        mq.push(n*r[n-1].second+r[n-2].second);
        if(r[n-1].first)
        {
            r[n - 1].first --;
            sum --;
        }
        if(r[n - 2].first)
        {
            r[n - 2].first --;
            sum --;
        }
        sort(r, r + n);
    }
    printf("%d\n%d\n",r[0].first,cnt);
    if(ch)  printf("%s\n",g);
    while(!mq.empty())
    {
        x = mq.front();
        mq.pop();
        s[x / n] = '1';
        s[x % n] = '1';
        printf("%s\n",s);
        s[x / n] = '0';
        s[x % n] = '0';
    }
    return 0;
}