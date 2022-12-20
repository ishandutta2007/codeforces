#include<bits/stdc++.h>
using namespace std;

const int nmax=600+42;

int n,m;

int adj[nmax][nmax];

long long outp[nmax][nmax];

long long dist[nmax];

bool been[nmax];

int score[nmax][nmax];

void dij(int node)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=1e18;
        been[i]=0;
    }

    dist[node]=0;

    for(int t=0;t<n;t++)
    {
        node=-1;

        for(int j=0;j<n;j++)
            if(been[j]==0)
            {
                if(node==-1)node=j;
                else if(dist[node]>dist[j])node=j;
            }

        //cout<<"t= "<<t<<" node= "<<node<<" dist= "<<dist[node]<<endl;

        been[node]=1;

        long long s=dist[node],s_new;

        int s_mod=s%n;

        int j_new;

        for(int j=0;j<n;j++)
        {
            j_new=j-s_mod;
            if(j_new<0)j_new+=n;

            s_new=s+score[node][j_new];

            dist[j]=min(dist[j],s_new);
        }
    }
}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;

        scanf("%i%i%i",&a,&b,&c);

        adj[a][b]=c;
    }

    for(int node=0;node<n;node++)
        for(int j=0;j<n;j++)
        {
            int s=0;

                score[node][j]=2e9;

                for(int i=0;i<n;i++)
                    if(adj[node][i])
                {
                    int s_new=j-i;
                    if(s_new<0)s_new+=n;

                    score[node][j]=min(score[node][j],s_new+adj[node][i]);
                }

                //cout<<"node= "<<node<<" j= "<<j<<" s= "<<s<<" score= "<<score[node][j]<<endl;

            //cout<<"---"<<endl;
        }


    for(int i=0;i<n;i++)
    {
        dij(i);

        for(int j=0;j<n;j++)printf("%lld ",dist[j]);

        printf("\n");
    }

    return 0;
}