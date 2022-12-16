#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,MX=1e6+42;

int h,w;

vector<int> l,p;

bitset<MX> can[nmax],idle;

pair< vector<int>, vector<int> > create(vector<int> cur)
{
    int sum=0;
    for(auto k:cur)
        sum+=k;

    //cout<<"sum= "<<sum<<endl;

    if(sum%2)return {{},{}};

    for(int i=1;i<=cur.size();i++)
        can[i]=idle;

    can[0][0]=1;

    for(int i=1;i<=cur.size();i++)
    {
        can[i]=can[i-1]|(can[i-1]<<cur[i-1]);
    }

    if(can[cur.size()][sum/2]==0)return {{},{}};

    sum=sum/2;

    vector<int> ret[2]={{},{}};

    for(int i=cur.size();i>=1;i--)
    {
        if(can[i-1][sum])ret[1].push_back(cur[i-1]);
        else
        {
            ret[0].push_back(cur[i-1]);
            sum=sum-cur[i-1];
        }
    }

    return {ret[0],ret[1]};
}

bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    l={};
    scanf("%i",&h);
    for(int i=1;i<=h;i++)
    {
        int sz;
        scanf("%i",&sz);
        l.push_back(sz);
    }

    p={};
    scanf("%i",&w);
    for(int i=1;i<=w;i++)
    {
        int sz;
        scanf("%i",&sz);
        p.push_back(sz);
    }

    if(h!=w)
    {
        printf("No\n");
        return;
    }

    pair< vector<int>, vector<int> > to_add_h=create(l);

    pair< vector<int>, vector<int> > to_add_w=create(p);

    if(to_add_h.first.size()==0||to_add_w.first.size()==0)
    {
        printf("No\n");
        return;
    }

    printf("Yes\n");

    if(to_add_h.first.size()>to_add_h.second.size())swap(to_add_h.first,to_add_h.second);
    if(to_add_w.first.size()<to_add_w.second.size())swap(to_add_w.first,to_add_w.second);

    sort(to_add_h.first.begin(),to_add_h.first.end(),cmp);
    sort(to_add_h.second.begin(),to_add_h.second.end(),cmp);

    sort(to_add_w.first.begin(),to_add_w.first.end());
    sort(to_add_w.second.begin(),to_add_w.second.end());

    vector<int> h_change={},w_change={};
    for(auto k:to_add_h.first)h_change.push_back(k);
    for(auto k:to_add_h.second)h_change.push_back(-k);

    for(auto k:to_add_w.first)w_change.push_back(k);
    for(auto k:to_add_w.second)w_change.push_back(-k);

    vector< pair<int,int> > outp={};
    for(int i=0;i<h;i++)
    {
        outp.push_back({h_change[i],0});
        outp.push_back({0,w_change[i]});
    }

    /*
    for(auto k:outp)
    {
        cout<<"change "<<k.first<<" "<<k.second<<endl;
    }
    */

    int x=0,y=0;

    for(auto k:outp)
    {
        printf("%i %i\n",x,y);

        x=x+k.first;
        y=y+k.second;
    }
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