#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,ans,ans2,max,index,d;cin>>n;
    long long int q;cin>>q;
    vector<long long int>v;
    max=-1;
    vector<pair<long long int,long long int>>v1;
    deque <int> gquiz,g; 
    for(long long int i=0;i<n;i++)
    {
        cin>>d;
        gquiz.push_back(d);
        if(d>max)
        {
            max=d;
            index=i;
        }
    }
    for(long long int i=0;i<index;i++)
    {
        ans=gquiz.front();
        gquiz.pop_front();
        ans2=gquiz.front();
        gquiz.pop_front();
        pair<long long int,long long int>p;
        p=make_pair(ans,ans2);
        v1.push_back(p);
        if(ans>ans2)
        {
            gquiz.push_back(ans2); 
            gquiz.push_front(ans);
        }
        else
        {
            gquiz.push_back(ans); 
            gquiz.push_front(ans2);
        }
    }
    g=gquiz;
    g.pop_front();
    for(long long int i=1;i<n;i++)
    {
        ans=g.front();
        g.pop_front();
        v.push_back(ans);
    }
    
    long long int u;
    for(long long int i=0;i<q;i++)
    {
        cin>>u;
        if(u<=index)
        {
            cout<<v1[u-1].first<<" "<<v1[u-1].second<<endl;
        }
        else
        {
            u=u-index;
            u=u%(n-1);
            if(u!=0)
            {
                cout<<max<<" "<<v[u-1]<<endl;
            }
            else
            {
                cout<<max<<" "<<v.back()<<endl;
            }
        }
    }
}
int main()
{
    solve(); 
}