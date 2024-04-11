#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m;

int match[nmax];
void solve()
{
    scanf("%i%i",&n,&m);
    for(int j=1;j<=3*n;j++)match[j]=0;

    int a,b;
    vector<int> in={};
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&a,&b);
        if(match[a]==0&&match[b]==0)
        {
            match[b]=a;
            match[a]=b;
            in.push_back(i);
        }
    }

    if(in.size()>=n)
    {
        printf("Matching\n");
        for(int i=0;i<n;i++)
            printf("%i ",in[i]);
        printf("\n");
        return;
    }

    printf("IndSet\n");
    int out=0;
    for(int i=1;i<=3*n;i++)
        if(match[i]==0)
        {
            printf("%i ",i);
            out++;
            if(out==n)break;
        }
    printf("\n");
}
int main()
{
    int t;
    scanf("%i",&t);
    for(int i=1;i<=t;i++)
        solve();



    return 0;
}