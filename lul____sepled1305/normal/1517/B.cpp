#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pair<int,int>>;
int dp[100][100], val[100][100];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        priority_queue<piii> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>val[i][j], dp[i][j] = 0, pq.push({-val[i][j],{i,j}});
        }
        for(int i=0;i<m;i++)
        {
            piii top = pq.top();
            pq.pop();
            dp[top.second.first][top.second.second] = i+1;
            //cout<<"SS "<<top.second.first<<' '<<top.second.second<<' '<<-top.first<<endl;
        }
        for(int i=0;i<n;i++)
        {
            map<int,int> mp;
            stack<int> st;
            for(int j=0;j<m;j++)
            {
                if(dp[i][j] != 0)
                {
                    //cout<<i<<' '<<j<<' '<<dp[i][j]-1<<" SS\n";
                    mp[dp[i][j]-1] = j;
                }
                else
                    st.push(val[i][j]);
            }
            for(int j=0;j<m;j++)
            {
                if(mp.count(j))
                    cout<<val[i][mp[j]]<<' ';
                else
                    cout<<st.top()<<' ', st.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}