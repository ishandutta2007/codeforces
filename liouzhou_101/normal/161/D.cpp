#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=50010;
const int MaxK=510;

int n,k;
vector<int> v[MaxN];
long long F[MaxN][MaxK];
int d[MaxN];

long long ans;

void DFS(int x)
{
    d[x]=1;
    F[x][0]=1;
    for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
    {
        int tmp=*it;
        if (!d[tmp])
        {
            DFS(tmp);
            for (int i=0;i<k;++i)
                ans+=(F[tmp][i]*F[x][k-i-1]);
            for (int i=0;i<k;++i)
                F[x][i+1]+=F[tmp][i];
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    cout<<ans<<endl;
    return 0;
}