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

int n,x;
const int ha[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    read(x);
    char ch=getchar();
    while (ch!='o') ch=getchar();
    getchar();getchar();
    ch=getchar();
    if (ch=='m')
    {
        int ans=0;
        for (int i=1;i<=12;i++)
        if (ha[i]>=x)   ans++;
        printf("%d\n",ans);
        return 0;
    }   else
    {
        int ans=0;
        if (x>=5)   ans++;
        int momo=366-3;
        ans+=momo/7;
        momo%=7;
        if (x<=momo)    ans++;
        printf("%d\n",ans);
        return 0;
    }
    return 0;
}