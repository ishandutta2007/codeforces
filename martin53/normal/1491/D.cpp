#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

int bits(int x)
{
    int ret=0;
    while(x)
    {
        ret=ret+x%2;
        x=x/2;
    }
    return ret;
}

vector<int> get_bits(int x)
{
    vector<int> ret={};
    for(int i=0;i<30;i++)
    {
        if(x%2)ret.push_back(i);
        x=x/2;
    }

    return ret;
}

int solve(int x,int y)
{
    if(x>y)return 0;

    vector<int> x_=get_bits(x),y_=get_bits(y);

    //cout<<x_.size()<<" "<<y_.size()<<endl;

    if(x_.size()<y_.size())return 0;

    //return x<=y&&bits(x)>=bits(y);
    for(int i=0;i<y_.size();i++)
        if(y_[i]<x_[i])return 0;

    return 1;
}

int u;

set<int> in={};

void dfs(int u)
{
    if(in.count(u))return;

    in.insert(u);

    for(int v=1;u+v<=255;v++)
        if(((u&v)==v))dfs(u+v);
}
void prec()
{
    /*
    for(int sum=1;sum<=255;sum++)
    {
        cout<<sum<<" -> ";
        for(int u=1;u<sum;u++)
        {
            int v=sum-u;

            if((u&v)==v)cout<<u<<" ";
        }
        cout<<endl;
    }
    return 0;
    */

    for(u=1;u<=255;u++)
    {
        in={};
        cout<<"u= "<<u<<" : ";
        dfs(u);

        //for(auto w:in)cout<<w<<" with "<<bits(w)<<", ";cout<<endl;

        for(int v=1;v<=255;v++)
        {
            if(solve(u,v)!=in.count(v))
            {
                cout<<"wrong "<<u<<" "<<v<<endl;
                cout<<solve(u,v)<<" "<<in.count(v)<<endl;

                system("pause");
            }
        }

    }
    exit(0);
}

int main()
{
    //prec();

    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        int x,y;
        scanf("%i%i",&x,&y);

        if(solve(x,y))printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}