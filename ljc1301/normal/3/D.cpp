#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=50005;
long long ans;
priority_queue<pair<int,int> > que;
char s[maxn];
int main()
{
    int i,a,b,now;
    bool ok;
    scanf("%s",s);
    for(i=0,now=0,ok=true;s[i];i++)
        if(s[i]=='(')
            now++;
        else
        {
            if(s[i]=='?')
            {
                s[i]=')';
                scanf("%d%d",&a,&b);
                ans+=b;
                que.push(make_pair(b-a,i));
            }
            now--;
            if(now<0)
            {
                if(que.empty())
                {
                    ok=false;
                    break;
                }
                ans-=que.top().first;
                s[que.top().second]='(';
                que.pop();
                now+=2;
            }
        }
    if(now>0) ok=false;
    if(!ok) printf("-1\n");
    else printf("%I64d\n%s\n",ans,s);
    return 0;
}