#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}
#define maxn 1000010
int n;
int ans,now,a[maxn];

int main()
{
    read(n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        int x;
        while (ch!='+' && ch!='-')  ch=getchar();
        read(x);
        if (ch=='+')
        {
            a[x]=1;
            now++;
            ans=max(ans,now);
        }
        if (ch=='-')
        {
            if (a[x]==1) a[x]=0,now--;
            else ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}