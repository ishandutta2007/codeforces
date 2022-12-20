#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<15);

int n;

int dist[nmax];

queue< pair<int,int> > q;

int main()
{
    memset(dist,-1,sizeof(dist));

    q.push({0,0});

    while(q.size())
    {
        pair<int,int> tp=q.front();

        q.pop();

        if(dist[tp.first]!=-1)continue;

        dist[tp.first]=tp.second;

        //cout<<tp.second<<" -> "<<tp.first<<endl;

        q.push({(tp.first-1+nmax)%nmax,tp.second+1});

        if(tp.first%2==0)
        {
            q.push({tp.first/2,tp.second+1});
            q.push({(tp.first+nmax)/2,tp.second+1});
        }
    }

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        printf("%i\n",dist[cur]);
    }

    return 0;
}