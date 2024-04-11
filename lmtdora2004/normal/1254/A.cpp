#include <bits/stdc++.h>

using namespace std;

vector<char> ans;

int n, m, k;
string s[200];
int cac[70];

void solve()
{
    cin>>n>>m>>k;
    int cr=0;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        s[i]='!'+s[i];
        for(int j=1; j<=m; j++)
        {
            if(s[i][j]=='R') cr++;
        }
    }
    int cut=cr%k;
    for(int i=0; i<k; i++)
    {
        cac[i]=cr/k;
    }
    for(int i=0; i<cut; i++)
    {
        cac[i]++;
    }
    int now=0, have=0;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i][j]=='R')
                {
                    cr--;
                    if(have==cac[now])
                    {
                        now++;
                        have=1;
                    }
                    else
                    {
                        have++;
                    }
                }
                else
                {
                    if(cr==0)
                    {
                        if(now<k-1)
                        {
                            now++;
                        }
                    }
                }
                s[i][j]=ans[now];
            }
        }
        else
        {
            for(int j=m; j>=1; j--)
            {
                if(s[i][j]=='R')
                {
                    cr--;
                    if(have==cac[now])
                    {
                        now++;
                        have=1;
                    }
                    else
                    {
                        have++;
                    }
                }
                else
                {
                    if(cr==0)
                    {
                        if(now<k-1)
                        {
                            now++;
                        }
                    }
                }
                s[i][j]=ans[now];
            }
        }   
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }
}

signed main()
{
    for(int i='a'; i<='z'; i++)
    {
        ans.push_back(i);
    }
    for(int i='A'; i<='Z'; i++)
    {
        ans.push_back(i);
    }
    for(int i='0'; i<='9'; i++)
    {
        ans.push_back(i);
    }
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        solve();
    }
}