#include<bits/stdc++.h>
using namespace std;
int T;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        int n,i,j,mini = 1e9;
        cin>>n;
        int a[n], dp[n], ori[n], dp_s[n], dp_e[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            ori[i] = a[i];
        }
        sort(ori,ori+n);
        map<int,int> mp;
        int counti = 0;
        mp.insert({ori[0],0});
        for(i=1;i<n;i++)
        {
            if(ori[i]!=ori[i-1])
            {
                counti++;
                mp.insert({ori[i],counti});
            }
        }
        counti++;
        vector<int> v[counti];
        int pointer[counti];
        for(i=0;i<counti;i++)
            pointer[i] = -1;
        for(i=0;i<n;i++)
        {
            int cur = mp[a[i]];
            v[cur].push_back(i);
        }
        for(i=0;i<n;i++)
        {
            bool pass = false;
            int cur = mp[a[i]];
 
            int can = 1e9;
            pointer[cur]++;
            if(pointer[cur] == 0 && cur>0 && pointer[cur-1]==v[cur-1].size()-1 && v[cur-1][pointer[cur-1]] < i)
            {
                can = dp[v[cur-1][pointer[cur-1]]] -1;
            }
            else if (pointer[cur] == 0 && cur>0 && pointer[cur-1]!=-1 && v[cur-1][pointer[cur-1]] < i)
            {
                can = dp_s[v[cur-1][pointer[cur-1]]] -1;
            }
            else if(pointer[cur] > 0)
            {
                can = dp[v[cur][pointer[cur]-1]] -1;
            }
            can = min(can,n-1);
            int s = v[cur].size();
            dp_s[i] = n-1-pointer[cur];
            dp[i] = min(dp_s[i],can);
            if(cur>0 && pointer[cur-1]==v[cur-1].size()-1 && v[cur-1][pointer[cur-1]] < i)
            {
                can = dp[v[cur-1][pointer[cur-1]]] -1;
            }
            else if (cur>0 && pointer[cur-1]!=-1 && v[cur-1][pointer[cur-1]] < i)
            {
                can = dp_s[v[cur-1][pointer[cur-1]]] -1;
            }
            dp_e[i] = min(dp[i] - s +1 + pointer[cur],can - s +1 + pointer[cur]);
 
            if(dp_e[i] < mini)
                mini = dp_e[i];
        }
        cout<<mini<<"\n";
    }
    return 0;
}