#include<bits/stdc++.h>
using namespace std;
int T;

int solve()
{
    int n,i,j;
    vector<int> ans;
    cin>>n;
    int domino[n][2];
    int inverse[n][2];
    bool visit[n];
    int counti[n];
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            inverse[j][i] = -1,counti[j] = 0;
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
        {
            int l;
            cin>>l;
            l--;
            counti[l]++;
            domino[j][i] = l;
            if(inverse[l][0]==-1)
                inverse[l][0] = j;
            else
                inverse[l][1] = j;
            visit[j] = false;
        }
    bool pass = true;
    for(i=0;i<n;i++)
    {
        if(counti[i]!=2)
            pass = false;
    }
    if(!pass)
    {
        cout<<"-1\n";
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(!visit[i])
        {
            vector<int> odd,even;
            int cur_val = domino[i][0],cur = i;
            while(!visit[cur])
            {
                visit[cur] = true;
                if(domino[cur][0] == domino[cur][1])
                    break;
                if(domino[cur][0]!=cur_val)
                    even.push_back(cur), swap(domino[cur][0],domino[cur][1]);
                else
                    odd.push_back(cur);
                cur_val = domino[cur][1];
                if(inverse[cur_val][0]==cur)
                    cur = inverse[cur_val][1];
                else
                    cur = inverse[cur_val][0];
            }
            if(odd.size()<=even.size())
            {
                while(!odd.empty())
                {
                    ans.push_back(odd.back());
                    odd.pop_back();
                }
            }
            else
            {
                while(!even.empty())
                {
                    ans.push_back(even.back());
                    even.pop_back();
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it: ans)
        cout<<it+1<<" ";
    cout<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
        solve();
    return 0;
}