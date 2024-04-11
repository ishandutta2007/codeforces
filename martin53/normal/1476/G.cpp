#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,q;

struct query
{
    int type,l,r,k;
};

query queries[nmax];

int inp[nmax],help[nmax];

int BIG,BLOCK;

vector<int> big_nums[nmax];

set<int> big_nums_active;

int seen[nmax],cnt_seen[nmax];

int outp[nmax];

int active_l,active_r;

void push(int val,int coeff)
{
    cnt_seen[seen[val]]--;
    seen[val]+=coeff;
    cnt_seen[seen[val]]++;
}

vector< pair<int/*cnt*/,int/*frequency*/> > active,extra;

int solve(int k,int id)
{
    active={};

    for(int i=1;i<BIG;i++)
        if(cnt_seen[i])
            active.push_back({i,cnt_seen[i]});

    extra={};

    for(auto w:big_nums[id])
        if(seen[w]>=BIG)
            extra.push_back({seen[w],1});

    sort(extra.begin(),extra.end());

    for(auto w:extra)
        active.push_back(w);

    for(int i=1;i<active.size();i++)
        active[i].second=active[i].second+active[i-1].second;

    if(active.back().second<k)return -1;

    int ret=1e9;

    int j=0;

    for(int i=0;i<active.size();i++)
    {
        while(j<active.size()&&active[j].second-(i?active[i-1].second:0)<k)j++;

        if(j==active.size())break;

        ret=min(ret,active[j].first-active[i].first);
    }

    return ret;
}
void solve_query(int id)
{
    int l=queries[id].l;
    int r=queries[id].r;

    while(active_l>l)
    {
        active_l--;
        push(help[active_l],1);
    }

    while(active_r<r)
    {
        active_r++;
        push(help[active_r],1);
    }

    while(active_l<l)
    {
        push(help[active_l],-1);
        active_l++;
    }

    while(active_r>r)
    {
        push(help[active_r],-1);
        active_r--;
    }

    outp[id]=solve(queries[id].k,id);
}
int main()
{
    scanf("%i%i",&n,&q);

    BLOCK=pow(n,2.0/3)+1;

    BIG=sqrt(n*log(n))+1;

    //cout<<"big= "<<BIG<<endl;

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=q;i++)
    {
        scanf("%i",&queries[i].type);

        if(queries[i].type==1)
        {
            scanf("%i%i%i",&queries[i].l,&queries[i].r,&queries[i].k);
        }
        else
        {
            scanf("%i%i",&queries[i].l,&queries[i].k);
        }
    }

    for(int i=1;i<=n;i++)
        seen[inp[i]]++;

    for(int i=1;i<nmax;i++)
        if(seen[i]>=BIG)
            big_nums_active.insert(i);

    for(int i=1;i<=n;i++)
        help[i]=inp[i];

    for(int i=1;i<=q;i++)
    {
        if(queries[i].type==2)
        {
            int pos=queries[i].l;

            if(seen[help[pos]]>=BIG)big_nums_active.erase(help[pos]);

            push(help[pos],-1);

            if(seen[help[pos]]>=BIG)big_nums_active.insert(help[pos]);

            help[pos]=queries[i].k;

            if(seen[help[pos]]>=BIG)big_nums_active.erase(help[pos]);

            push(help[pos],1);

            if(seen[help[pos]]>=BIG)big_nums_active.insert(help[pos]);
        }
        /*
        cout<<"help: ";for(int j=1;j<=n;j++)cout<<help[j]<<" ";cout<<endl;
        cout<<"seen: ";for(int j=1;j<=n;j++)cout<<seen[j]<<" ";cout<<endl;

        cout<<i<<" -> ";
        */
        for(auto w:big_nums_active)
        {
            big_nums[i].push_back(w);
            //cout<<w<<" ";
        }
        //cout<<endl;
    }


    for(int lq=0;lq<=n/BLOCK;lq++)
        for(int rq=lq;rq<=n/BLOCK;rq++)
        {
            for(int i=1;i<=n;i++)
                help[i]=inp[i];

            active_l=1;
            active_r=0;

            memset(seen,0,sizeof(seen));
            memset(cnt_seen,0,sizeof(cnt_seen));

            for(int i=1;i<=q;i++)
            {
                if(queries[i].type==2)
                {
                    if(active_l<=queries[i].l&&queries[i].l<=active_r)
                    {
                        push(help[queries[i].l],-1);
                        help[queries[i].l]=queries[i].k;
                        push(help[queries[i].l],+1);
                    }
                    else
                    {
                        help[queries[i].l]=queries[i].k;
                    }
                }
                else if(queries[i].l/BLOCK==lq&&queries[i].r/BLOCK==rq)
                {
                    solve_query(i);
                }
            }

        }

    for(int i=1;i<=q;i++)
        if(queries[i].type==1)
            printf("%i\n",outp[i]);

    return 0;
}