#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int MaxN=1000100;

int n,m;
vector<int> edge[MaxN];
long long ans;
int p[MaxN],len[MaxN];
long double Hash[MaxN],s[MaxN],t[MaxN];

inline void read(int &x)
{
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    x=c-48;
    while (1)
    {
        c=getchar();
        if (c>'9'||c<'0') break;
        x=x*10+c-48;
    }
}

void init()
{
    cin>>n>>m;
    int i,x,y;
    for (i=1;i<=m;++i)
    {
        read(x);
        read(y);
        edge[x].push_back(y);
        ++len[x];
        edge[y].push_back(x);
        ++len[y];
    }
}

bool cmp(const int &i,const int &j)
{
    if (len[i]<len[j]) return true;
    if (len[i]>len[j]) return false;
    return Hash[i]<Hash[j];
}

void work()
{
    for (int i=1;i<=n;++i)
        p[i]=i;
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;++i)
    {
        long long tmp=1;
        int j=i;
        if (j<n)
        while (len[p[j+1]]==len[p[j]]&&Hash[p[j+1]]==Hash[p[j]])
        {
            ++j;
            ++tmp;
            if (j==n) break;
        }
        ans+=(tmp*(tmp-1)/2);
        i=j;
    }
}

int main()
{
    init();
    srand(time(0));
    for (int i=1;i<=n;++i)
    {
        s[i]=rand()+1;
        t[i]=rand()+1;
    }
    for (int i=1;i<=n;++i)
    {
        sort(edge[i].begin(),edge[i].end());
        int k=1;
        Hash[i]=0;
        for (vector<int>::iterator it=edge[i].begin();it!=edge[i].end();++it,++k)
            Hash[i]+=((*it)*s[k]*(*it)/t[k]);
    }
    work();
    for (int i=1;i<=n;++i)
    {
        edge[i].push_back(i);
        sort(edge[i].begin(),edge[i].end());
        int k=1;
        Hash[i]=0;
        for (vector<int>::iterator it=edge[i].begin();it!=edge[i].end();++it,++k)
            Hash[i]+=((*it)*s[k]*(*it)/t[k]);
    }
    work();
    cout<<ans<<endl;
    return 0;
}