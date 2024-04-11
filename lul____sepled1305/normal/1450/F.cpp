/** Ithea Myse Valgulious **/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;

struct segment
{
    int l,r;
    int h,t;

    segment(int a, int b, int c, int d)
    {
        l=a,r=b,h=c,t=d;
    }
};

void solve()
{
    vector<segment> seg;
    vector<int> v;
    int n,i,j,a,b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        a--;
        v.push_back(a);
    }
    int pointer = 0;
    for(i=0;i<n-1;i++)
    {
        if(v[i] == v[i+1])
            seg.push_back(segment(pointer,i,v[pointer],v[i])),pointer = i+1;
    }
    seg.push_back(segment(pointer,n-1,v[pointer],v[n-1]));
    int maxi = 0;
    int cur_max = -1;
    map<int,int> mp;
    for(auto it: seg)
    {
        if(!mp.count(it.h))
            mp.insert({it.h,0});
        mp[it.h]++;
        if(!mp.count(it.t))
            mp.insert({it.t,0});
        mp[it.t]++;

        if(mp[it.h] > maxi)
        {
            maxi = mp[it.h];
            cur_max = it.h;
        }
        if(mp[it.t] > maxi)
        {
            maxi = mp[it.t];
            cur_max = it.t;
        }
    }
    if(maxi <= seg.size()+1)
        cout<<seg.size()-1<<endl;
    else
    {
        int counti = 0;
        int left = maxi - seg.size() -1;
        for(auto it: seg)
        {
            for(i=it.l;i<it.r;i++)
            {
                if(v[i]!=cur_max && v[i+1]!=cur_max)
                    counti++;
            }
        }
        if(counti < left)
            cout<<"-1\n";
        else
        {
            cout<<maxi-2<<endl;
        }
    }
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}