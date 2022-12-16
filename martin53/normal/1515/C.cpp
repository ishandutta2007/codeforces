#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

priority_queue< pair<int,int> > pq,idle;

int n,m,x,inp[nmax];
int outp[nmax];

void solve()
{
    scanf("%i%i%i",&n,&m,&x);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)outp[i]=0;

    pq=idle;

    for(int i=1;i<=m;i++)pq.push({0,i});

    for(int i=1;i<=n;i++)
    {
        pair<int,int> tp=pq.top();
        pq.pop();

        outp[i]=tp.second;

        tp.first-=inp[i];

        pq.push(tp);
    }

    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
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