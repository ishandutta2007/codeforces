#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n,inp[nmax];

pair<long long,int> fenwick[nmax];

void update(int val)
{
    int pos=val;

    while(pos<nmax)
    {
        fenwick[pos].first+=val;
        fenwick[pos].second++;

        pos=pos+(pos&(-pos));
    }
}

pair<long long,int> query(int pos)
{
    pos=min(pos,nmax-1);

    pair<long long,int> ret={0,0};

    while(pos>0)
    {
        ret.first+=fenwick[pos].first;
        ret.second+=fenwick[pos].second;

        pos=pos-(pos&(-pos));
    }

    return ret;
}
pair<long long,int> sum(int l,int r)
{
    pair<long long,int> val_r=query(r);
    pair<long long,int> val_l=query(l-1);

    return {val_r.first-val_l.first,val_r.second-val_l.second};
}

long long outp=0;

int given_c;

bool on[nmax];

void add(int val)
{
    for(int i=0;i*val<nmax;i++)
    {
        pair<long long,int> help=sum(i*val,i*val+val-1);

        outp+=help.first-1LL*i*val*help.second;
    }

    outp+=1LL*sum(0,nmax).second*val;

    given_c=val;

    /*
    int coeff=given_c/l;

    outp=outp-1LL*coeff*sum(l,r).first;
    */

    int remain=given_c;

    int stop=sqrt(remain)+1;

    for(int f=1;remain>=stop;f++)
    {
        int low=(given_c+1+f+1-1)/(f+1);
        int high=(given_c)/(f);

        //cout<<"val= "<<val<<" "<<low<<" "<<high<<" f= "<<f<<endl;

        if(low<=high)
        {
            //cout<<"sub "<<f<<" * "<<sum(low,high).first<<endl;

            outp=outp-1LL*f*sum(low,high).first;

            remain=low-1;
        }
    }

    while(remain)
    {
        //cout<<"remain= "<<remain<<endl;

        if(on[remain])outp=outp-given_c/remain*remain;

        remain--;
    }

    update(val);

    on[val]=1;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        add(inp[i]);
        printf("%lld ",outp);
    }

    return 0;
}