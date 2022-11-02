/**
    Ithea Myse Valgulious
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int T;

void solve()
{
    string s;
    int x,y,i;
    ll ans = 1e18;
    ll sum = 0;
    stack<int> st;
    cin>>s;
    cin>>x>>y;
    ll counti[2][2];
    counti[0][0] = 0, counti[0][1] = 0;
    counti[1][0] = 0, counti[1][1] = 0;
    for(i=0;i<s.size();i++)
    {
        ll turn;
        if(s[i] == '?')
            counti[0][0]++,turn = 0;
        else
        {
            counti[s[i]-'0'][0]++, turn = s[i]-'0';
        }
        if(turn == 0)
            sum+=1LL*counti[1][0]*y;
        else
            sum+=1LL*counti[0][0]*x;
    }
    ans = min(ans,sum);
    for(i=s.size()-1;i>=0;i--)
    {
        if(s[i] == '?')
        {
            counti[0][0]--;
            sum += x*(counti[0][0] - counti[1][1]);
            sum += y*(counti[0][1] - counti[1][0]);
            counti[1][1]++;
        }
        else
        {
            counti[s[i]-'0'][1]++;
            counti[s[i]-'0'][0]--;
        }
        ans = min(sum,ans);
    }
    sum = 0;
    counti[0][0] = 0, counti[0][1] = 0;
    counti[1][0] = 0, counti[1][1] = 0;
    for(i=0;i<s.size();i++)
    {
        ll turn;
        if(s[i] == '?')
            counti[1][0]++,turn = 1;
        else
        {
            counti[s[i]-'0'][0]++, turn = s[i]-'0';
        }
        if(turn == 0)
            sum+=1LL*counti[1][0]*y;
        else
            sum+=1LL*counti[0][0]*x;
    }
    ans = min(ans,sum);
    for(i=s.size()-1;i>=0;i--)
    {
        if(s[i] == '?')
        {
            counti[1][0]--;
            sum += x*(- counti[0][0] + counti[1][1]);
            sum += y*(- counti[0][1] + counti[1][0]);
            counti[0][1]++;
        }
        else
        {
            counti[s[i]-'0'][1]++;
            counti[s[i]-'0'][0]--;
        }
        ans = min(sum,ans);
    }
    cout<<ans;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/
    solve();
    return 0;
}