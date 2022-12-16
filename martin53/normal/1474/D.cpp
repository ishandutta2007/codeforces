#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

int LHS[nmax],RHS[nmax];

bool check(int a,int b,int c,int d)
{
    int arr[4]={a,b,c,d};

    for(int i=1;i<4;i++)
    {
        if(arr[i-1]>arr[i])return 0;
        arr[i]=arr[i]-arr[i-1];
        arr[i-1]=0;
    }

    return arr[3]==0;
}

bool valid(int a,int b,int c,int d)
{
    if(a==-1||d==-1)return 0;

    return check(a,b,c,d)||check(a,c,b,d);
}

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        if(LHS[i-1]==-1)LHS[i]=-1;
        else if(LHS[i-1]<=inp[i])LHS[i]=inp[i]-LHS[i-1];
        else LHS[i]=-1;
    }

    RHS[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        if(RHS[i+1]==-1)RHS[i]=-1;
        else if(RHS[i+1]<=inp[i])RHS[i]=inp[i]-RHS[i+1];
        else RHS[i]=-1;
    }

    for(int i=1;i<n;i++)
        if(valid(LHS[i-1],inp[i],inp[i+1],RHS[i+2]))return 1;

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}