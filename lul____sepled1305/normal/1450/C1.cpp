/** Ithea Myse Valgulious **/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;

bool check_row(int i, int j, string s[])
{
    bool pass = false;
    if(j >= 2)
    {
        if(s[i][j]==s[i][j-1] && s[i][j-1] == s[i][j-2])
            pass = true;
    }
    if(j >= 1 && j<s[i].size() -1)
    {
        if(s[i][j+1]==s[i][j] && s[i][j-1] == s[i][j])
            pass = true;
    }
    if(j<s[i].size()-2)
    {
        if(s[i][j+2]==s[i][j+1] && s[i][j+1] == s[i][j])
            pass = true;
    }
    if(s[i][j] == '.')
        pass = false;
    return pass;
}

bool check_col(int i, int j, string s[])
{
    bool pass = false;
    if(i >= 2)
    {
        if(s[i-2][j]==s[i-1][j] && s[i-1][j] == s[i][j])
            pass = true;
    }
    if(i >= 1 && i<s[i].size() -1)
    {
        if(s[i+1][j]==s[i][j] && s[i-1][j] == s[i][j])
            pass = true;
    }
    if(i<s[i].size()-2)
    {
        if(s[i+2][j]==s[i+1][j] && s[i+1][j] == s[i][j])
            pass = true;
    }
    if(s[i][j] == '.')
        pass = false;
    return pass;
}

void solve()
{
    int n,i,j;
    cin>>n;
    int counti = 0;
    string s[n+5];
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j] != '.')
                counti++;
        }
    }
    int change = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%3 == j%3 && (check_col(i,j,s) || check_row(i,j,s)))
                s[i][j] = 'O',change++;
        }
    }
    if(change > counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j] == 'O')
                    s[i][j] = 'X';
            }
        }
        change = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i%3+1)%3 == j%3 && (check_col(i,j,s) || check_row(i,j,s)))
                    s[i][j] = 'O',change++;
            }
        }
    }
    if(change > counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j] == 'O')
                    s[i][j] = 'X';
            }
        }
        change = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i%3+2)%3 == j%3 && (check_col(i,j,s) || check_row(i,j,s)))
                    s[i][j] = 'O',change++;
            }
        }
    }
    if(change > counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j] == 'O')
                    s[i][j] = 'X';
            }
        }
        change = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i+j)%3 == 0 && (check_col(i,j,s) || check_row(i,j,s)))
                    s[i][j] = 'O',change++;
            }
        }
    }
    if(change > counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j] == 'O')
                    s[i][j] = 'X';
            }
        }
        change = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i+j)%3 == 1 && (check_col(i,j,s) || check_row(i,j,s)))
                    s[i][j] = 'O',change++;
            }
        }
    }
    if(change > counti/3)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j] == 'O')
                    s[i][j] = 'X';
            }
        }
        change = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i+j)%3 == 2 && (check_col(i,j,s) || check_row(i,j,s)))
                    s[i][j] = 'O',change++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<s[i][j];
        cout<<"\n";
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