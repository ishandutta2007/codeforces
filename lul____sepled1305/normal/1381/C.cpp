/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,x,y,i,j,newi;
        cin>>n>>x>>y;
        int bob[n];
        int quick_color[n+2];
        bool appear[n+2];
        vector<int> quick[n+2];
        int alice[n];
        for(i=0;i<n+2;i++)
            appear[i] = false;
        for(i=0;i<n;i++)
            cin>>bob[i],alice[i] = -1,appear[bob[i]] = true;
        for(i=0;i<n+2;i++)
            quick_color[i] = 0;
        for(i=0;i<n;i++)
            quick[bob[i]].push_back(i);
        for(i=0;i<n;i++)
            quick_color[bob[i]]++;
        vector<pii> color;
        for(i=0;i<n+2;i++)
            color.push_back({quick_color[i],i});
        sort(color.begin(),color.end(),greater<pii>());
        if(y<x)
        {
            cout<<"NO\n";
            continue;
        }
        int cur = 0;
        priority_queue<pii> pq;
        for(i=0; i<n+2; i++)
        {
            pq.push(color[i]);
        }
        y-=x;
        newi = n-x;
        while(x>0)
        {
            x--;
            pii here = pq.top();
            pq.pop();
            pq.push({here.first-1,here.second});
            int col = here.second;
            alice[quick[col].back()] = here.second;
            quick[col].pop_back();
        }
        vector<pii> fi;
        while(!pq.empty())
        {
            pii here = pq.top();
            pq.pop();
            fi.push_back(here);
        }
        for(i=1;i<n+2;i++)
            cur+=fi[i].first;
        int fi_cal = fi[0].first -cur;
        if(fi_cal > newi-y)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            int pointer1 = 0, pointer2 = 0;
            while(y>0)
            {
                if(pointer1 == pointer2)
                    pointer2++;
                if(fi[pointer1].first>0)
                {
                    fi[pointer1].first--;
                    int col = fi[pointer1].second;
                    while(quick[fi[pointer2].second].size() == 0)
                    {
                        pointer2++;
                        if(pointer2==n+2)
                            pointer2 = 0;
                    }
                    if(pointer1 == pointer2)
                    {
                        pointer1++;
                        continue;
                    }
                    alice[quick[fi[pointer2].second].back()] = col;
                    quick[fi[pointer2].second].pop_back();
                    y--;
                }
                else
                    pointer1++;
            }
            int non;
            for(i=1;i<n+2;i++)
            {
                if(!appear[i])
                    non = i;
            }
            for(i=0;i<n;i++)
            {
                if(alice[i]==-1)
                    alice[i] = non;
            }
            for(i=0;i<n;i++)
                cout<<alice[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/