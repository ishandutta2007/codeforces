/** Ithea Myse Valgulious **/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;
int n;
string s[500];

bool color(int a, int b)
{
    int change=0,counti=0,i,j;
    set<pii> rev;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j] != '.')
                counti++;

            if(s[i][j] == 'X' && (i+j)%3 == a)
                change++,s[i][j] = 'O',rev.insert({i,j});
            if(s[i][j] == 'O' && (i+j)%3 == b)
                change++,s[i][j] = 'X',rev.insert({i,j});
        }
    }
    if(change <= counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<s[i][j];
            cout<<endl;
        }
        return true;
    }
    else
    {
        auto it = rev.begin();
        while(it != rev.end())
        {
            pii cur = *it;
            if(s[cur.first][cur.second] == 'X')
                s[cur.first][cur.second] = 'O';
            else
                s[cur.first][cur.second] = 'X';
            it++;
        }
        return false;
    }
}

void solve()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    if(color(0,1))
        return;
    if(color(0,2))
        return;
    if(color(1,0))
        return;
    if(color(1,2))
        return;
    if(color(2,0))
        return;
    if(color(2,1))
        return;
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