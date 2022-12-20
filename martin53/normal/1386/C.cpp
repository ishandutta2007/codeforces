#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+42;

int n,m,q,MX[nmax];

pair<int,int> inp[nmax];

pair<int,int> query[nmax];

int parent[nmax];

pair<int/*small*/,int/*big*/> performed[nmax];
int pointer=0;

int add[nmax];

bool my_merge(int u,int v)
{
    /*
    cout<<"current: ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;
    cout<<"my merge "<<u<<" "<<v<<endl;
    cout<<"---"<<endl;
    */

    int step_u=0,step_v=0,sum_u=0,sum_v=0;

    while(parent[u]!=u)sum_u+=add[u],u=parent[u],step_u++;

    while(parent[v]!=v)sum_v+=add[v],v=parent[v],step_v++;

    if(step_u<step_v){swap(u,v);swap(sum_u,sum_v);}

    sum_u=sum_u%2;
    sum_v=sum_v%2;

    if(u==v)
    {
        if(sum_u==sum_v)return 0;
        return 1;
    }

    pointer++;

    parent[v]=u;
    performed[pointer]={v,u};

    add[v]=!(sum_u^sum_v);

    return 1;
}
int brute(int start)
{
    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=start;i<=2*m;i++)
        if(my_merge(inp[i].first,inp[i].second)==0)
        {
            pointer=0;
            for(int j=1;j<=n;j++)parent[j]=j;

            return i-1;
        }

    pointer=0;
    for(int j=1;j<=n;j++)parent[j]=j;

    return 2*m;
}

void pop(int up)
{
    while(pointer>=up)
    {
        add[performed[pointer].first]=0;

        parent[performed[pointer].first]=performed[pointer].first;
        pointer--;
    }
}

void extend(int l_now,int r_now,int l_want,int r_want)
{
    if(l_want>r_want)return;

    if(l_now>r_now)l_now=l_want+1,r_now=l_want;

    for(int j=l_now-1;j>=l_want;j--)
        my_merge(inp[j].first,inp[j].second);

    for(int j=r_now+1;j<=r_want;j++)
        my_merge(inp[j].first,inp[j].second);
}
void solve(int l,int ans_l,int r,int ans_r)
{
    /*
    cout<<"solve "<<l<<" "<<ans_l<<" "<<r<<" "<<ans_r<<endl;

    for(int i=r;i<=ans_l;i++)cout<<inp[i].first<<" "<<inp[i].second<<"\t";cout<<endl;

    for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;

    cout<<"pointer: "<<pointer<<endl;

    for(int i=1;i<=pointer;i++)cout<<performed[i].first<<" "<<performed[i].second<<"\t";cout<<endl;

    cout<<"---"<<endl;
    */

    if(r-l<=1)return;

    //[r, ans_l] is in
    int av=(l+r)/2;

    int mem_pointer=pointer;

    if(ans_l<r)
    {
        MX[av]=brute(av);
    }
    else
    {
        mem_pointer=pointer;

        for(int j=av;j<r;j++)
            my_merge(inp[j].first,inp[j].second);

        MX[av]=ans_l+1;

        while(MX[av]<=ans_r&&my_merge(inp[MX[av]].first,inp[MX[av]].second))MX[av]++;

        MX[av]--;

        pop(mem_pointer+1);
    }
        extend(r,ans_l,av,ans_l);

        solve(l,ans_l,av,MX[av]);

        pop(mem_pointer+1);

        extend(r,ans_l,r,MX[av]);

        solve(av,MX[av],r,ans_r);

        pop(mem_pointer+1);
}

int main()
{
    scanf("%i%i%i",&n,&m,&q);
    for(int i=1;i<=m;i++)
        scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int i=m+1;i<=2*m;i++)
        inp[i]=inp[i-m];

    for(int i=m+1;i<=2*m;i++)
    {
        if(rand()%2)swap(inp[i].first,inp[i].second);
    }

    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);

        query[i]={r+1,l+m-1};
    }

    MX[1]=brute(1);

    if(MX[1]==2*m)
    {
        for(int i=1;i<=2*m;i++)MX[i]=2*m;
    }
    else
    {
        int j=2*m;
        for(int i=1;i<=n;i++)parent[i]=i;

        while(j>=1)
        {
            if(my_merge(inp[j].first,inp[j].second)==0){j++;break;}
            j--;
        }

        MX[j]=brute(j);

        for(int k=j+1;k<=2*m;k++)MX[k]=2*m;

        for(int i=1;i<=n;i++)parent[i]=i;

        for(int p=j;p<=MX[1];p++)
            my_merge(inp[p].first,inp[p].second);

        solve(1,MX[1],j,MX[j]);
    }

    /*
    for(int i=1;i<=2*m;i++)
    {
        cout<<"\t "<<i<<" -> "<<MX[i]<<" "<<brute(i)<<endl;
    }
    */


    for(int i=1;i<=q;i++)
        if(MX[query[i].first]<query[i].second)printf("YES\n");
        else printf("NO\n");
    return 0;
}