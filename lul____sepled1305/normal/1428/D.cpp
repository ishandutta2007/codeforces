#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1e5+10;
int n,i,j,k,l,h;
int a[N];
vector<int> ans[N];

vector<pii> th,tw;
vector<int> one;
queue<int> three, two;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if(a[i] == 3)
        {
            if(!three.empty())
            {
                int cur = three.front();
                three.pop();
                th.push_back({cur,i});
            }
            three.push(i);
        }
        if(a[i] == 2)
        {
            if(!three.empty())
            {
                int cur = three.front();
                th.push_back({cur,i});
                three.pop();
            }
            two.push(i);
        }
        if(a[i] == 1)
        {
            if(!two.empty())
            {
                int cur = two.front();
                two.pop();
                tw.push_back({cur,i});
            }
            else if(!three.empty())
            {
                int cur = three.front();
                th.push_back({cur,i});
                three.pop();
                one.push_back(i);
            }
            else
                one.push_back(i);
        }
    }
    if(!three.empty() || !two.empty())
    {
        cout<<-1;
        return 0;
    }

    h = n;
    while(!one.empty())
    {
        ans[one.back()].push_back(h);
        h--;
        one.pop_back();
    }
    while(!tw.empty())
    {
        pii cur = tw.back();
        ans[cur.first].push_back(h);
        ans[cur.second].push_back(h);
        h--;
        tw.pop_back();
    }
    while(!th.empty())
    {
        pii cur = th.back();
        ans[cur.first].push_back(h);
        ans[cur.second].push_back(h);
        h--;
        th.pop_back();
    }

    int coun = 0;
    for(i=0;i<n;i++)
        coun+=ans[i].size();

    cout<<coun<<endl;
    for(i=0;i<n;i++)
    {
        while(!ans[i].empty())
        {
            cout<<ans[i].back()<<' '<<i+1<<endl;
            ans[i].pop_back();
        }
    }
    return 0;
}