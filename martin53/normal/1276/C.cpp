#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+42;
int n,input[nmax];

map<int,int> seen;

int id=0;
int seen_times[nmax];

vector< vector<int> > output;

int proper(int num,int md)
{
    num=num%md;
    num=(num+md)%md;
    return num;
}


int p_out=0,q_out=0;
bool cmp(pair<int/*x*/,int/*y*/> a,pair<int/*x*/,int/*y*/> b)
{
    int u=proper(a.second-a.first,q_out);
    int v=proper(b.second-b.first,q_out);

    if(u!=v)return u<v;

    return a.first<b.first;
}
void fill_output(int p,int q)//p<=q
{
    //cout<<"p= "<<p<<" q= "<<q<<endl;
    vector<int> out={};
    for(int i=0;i<q;i++)out.push_back(0);

    for(int i=0;i<p;i++)output.push_back(out);

    vector< pair<int/*times*/,int/*number*/> > to_fill={};

    int want=p*q;
    for(auto k:seen)
    {
        //cout<<"k "<<k.first<<" "<<k.second<<endl;
        int current=min(min(k.second,p),want);
        //cout<<"current= "<<current<<endl;

        if(current)to_fill.push_back({current,k.first});
        want=want-current;
    }

    sort(to_fill.begin(),to_fill.end());
    p_out=p;
    q_out=q;

    vector< pair<int/*x*/,int/*y*/> > possible={};

    for(int i=0;i<p;i++)
        for(int j=0;j<q;j++)
            possible.push_back({i,j});

    sort(possible.begin(),possible.end(),cmp);

    //for(auto k:possible)cout<<k.first<<" "<<k.second<<" \t ";cout<<endl;

    int j=0;

    for(int i=to_fill.size()-1;i>=0;i--)
    {
        //cout<<i<<" ->" <<to_fill[i].first<<" "<<to_fill[i].second<<endl;

        for(int t=0;t<to_fill[i].first;t++)
        {
            output[possible[j].first][possible[j].second]=to_fill[i].second;
            j++;
        }
    }

    printf("%i\n",p*q);
    printf("%i %i\n",p,q);
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)printf("%i ",output[i][j]);
        printf("\n");
    }
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&input[i]);

    for(int i=1;i<=n;i++)
        seen[input[i]]++;

    for(auto k:seen)
    {
        seen_times[k.second]++;
    }


    int mx=0,p_=0,q_=0;

    int sum_seen_times=0,remain=seen.size();
    for(int p=1;p*p<=n;p++)
    {
        sum_seen_times+=p*seen_times[p];
        remain=remain-seen_times[p];

        int q_mx=(sum_seen_times+remain*p)/p;

        if(p<=q_mx&&mx<p*q_mx)
        {
            p_=p;
            q_=q_mx;
            mx=p*q_mx;
        }
    }

    fill_output(p_,q_);
    return 0;
}