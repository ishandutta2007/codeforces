#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;
int n,m;

vector<int> seen[nmax];

int SZ[nmax],outp[nmax],cnt[nmax];

void solve()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%i",&SZ[i]);

        seen[i]={};

        for(int j=1;j<=SZ[i];j++)
        {
            int num;
            scanf("%i",&num);

            seen[i].push_back(num);
        }
    }

    for(int i=1;i<=m;i++)outp[i]=0;

    for(int i=1;i<=n;i++)cnt[i]=0;

    for(int i=1;i<=m;i++)
        if(seen[i].size()==1)
        {
            outp[i]=seen[i][0];
            cnt[seen[i][0]]++;
        }

    int on=(m+1)/2;

    for(int i=1;i<=m;i++)
        if(seen[i].size()>1)
        {
            bool ok=0;

            for(auto w:seen[i])
                if(cnt[w]+1<=on)
                {
                    outp[i]=w;
                    cnt[w]++;
                    ok=1;
                    break;
                }

            if(ok==0)
            {
                printf("NO\n");
                return;
            }
        }

    for(int i=1;i<=n;i++)
        if(cnt[i]>on)
        {
            printf("NO\n");
            return;
        }

    printf("YES\n");
    for(int i=1;i<=m;i++)printf("%i ",outp[i]);
    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}