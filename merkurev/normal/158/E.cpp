#include <iostream>
#include <algorithm>
using namespace std;


pair <int,int> talk[4005];

int bestEnd[4005][4005];


void main()
{
   // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);

    //bestEnd: (- )x(- ) -> (  ) 
    for (int i=1;i<4005;i++)
        for (int j=0;j<4005;j++)
            bestEnd[i][j]=86401;


    int n,k;
    scanf("%d%d",&n,&k);
    if (n==0)
    {
        printf("86400");
        return ;
    }
    for (int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        talk[i]=make_pair(x,y);
    }
    sort(talk,talk+n);
    talk[n]=make_pair(86401,1);

    int ans=0;

    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
        {
            int offyet=i-j;
            if (offyet<=k)
            {
                int nxt=i+k-offyet;
                if (nxt>n)
                    nxt=n;
                int stnxt=min(86401,talk[nxt].first);
                int curans=stnxt-max(bestEnd[i][j],1);
                ans = max(ans,curans);
            }
        

            bestEnd[i+1][j]=min(bestEnd[i+1][j],bestEnd[i][j]);
            bestEnd[i+1][j+1]=min(bestEnd[i+1][j+1],max(bestEnd[i][j],talk[i].first)+talk[i].second);
        }
    printf("%d",ans);
}