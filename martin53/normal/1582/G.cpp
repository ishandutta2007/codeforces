#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

char read_char()
{
    char c=getchar();
    while(c!='*'&&c!='/')c=getchar();
    return c;
}

vector< pair<int,int> > seen[nmax];

int lowest[nmax];
void prec()
{
    for(int i=1;i<nmax;i++)lowest[i]=i;

    for(int p=2;p<nmax;p++)
        if(p==lowest[p])
        {
            seen[p].push_back({0,1e9});

            if(1LL*p*p<nmax)
            {
                for(int i=p*p;i<nmax;i=i+p)
                    if(lowest[i]==i)
                        lowest[i]=p;
            }
        }
}

int n;
int inp[nmax];

stack<int> ST;

void update(int node,int l,int r,int lq,int rq)
{
    while(ST.size()&&ST.top()>=lq)ST.pop();
}

void push(int id,int p,int coeff,int type)
{
    if(type==1)
    {
        seen[p].push_back({id,coeff});

        return;
    }

    //type=-1
    while(coeff)
    {
        update(1,0,n,seen[p].back().first+1,id);

        int sub=min(seen[p].back().second,coeff);
        coeff-=sub;
        seen[p].back().second-=sub;

        if(seen[p].back().second==0)seen[p].pop_back();
    }
}

int main()
{
    prec();

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
        scanf("%i",&inp[i]);

    long long outp=0;

    for(int i=1;i<=n;i++)
    {
        ST.push(i);

        char c=read_char();

        vector< pair<int,int> > dvd={};
        while(inp[i]>1)
        {
            if(dvd.size()&&dvd.back().first==lowest[inp[i]])dvd.back().second++;
            else dvd.push_back({lowest[inp[i]],1});

            inp[i]/=lowest[inp[i]];
        }

        //cout<<"dvd: ";for(auto w:dvd)cout<<w.first<<" "<<w.second<<"\t";cout<<endl;

        for(auto w:dvd)
            push(i,w.first,w.second,(c=='*'?1:-1));

        outp+=ST.size();
    }

    printf("%lld\n",outp);

    return 0;
}