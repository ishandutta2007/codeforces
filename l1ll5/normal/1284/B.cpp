#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define fi first
#define se second
#define int long long
int n;
vector<int> v[N];
bool dow[N];
pair<int,int> p[N];
const int maxn=1000005;
int c[maxn+5];
void add(int x,int v)
{
    for(int i=x;i<=maxn;i+=i&(-i))
    c[i]+=v;
}
int ask(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&(-i))
    ret+=c[i];
    return ret;
}
main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int l=read();
        for(int j=1;j<=l;j++)
        {
            int x=read()+1;
            v[i].push_back(x);
        }
        //    v[j]=read();
    }
//cerr<<"t"<<endl;
    for(int i=1;i<=n;i++)
    {
        bool fdow=1;
        for(int j=0;j<v[i].size()-1;j++)
        {
            if(v[i][j]<v[i][j+1])
            {
                fdow=0; break ;
            }
            //cerr<<i<<' '<<j<<' '<<endl;
        }
        //cerr<<i<<endl;
        dow[i]=fdow;
        //if(dow)
    }
    //cerr<<"t";
    ll ans=n*n;
    int top=0;
    for(int i=1;i<=n;i++)
    if(dow[i])
    {
        top++;
        p[top].fi=v[i][0];
        p[top].se=v[i][v[i].size()-1];
    }
    sort(p+1,p+top+1);

    for(int i=1;i<=top;i++)
    {
        add(p[i].fi,1);
    }

    for(int i=1;i<=top;i++)
    {
        ll ret=ask(p[i].se);
        ans-=ret;
    }
    cout<<ans<<endl;
}