#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,run;
string N[10];
int dp[2010][2010];

int check(string &ss, int b)
{
    int h,ans=0;
    bool pass=true;
    for(h=0;h<7;h++)
    {
        if(ss.at(h) == '1' && N[b].at(h) == '0')
            pass =false;
        else if (ss.at(h) == '0' && N[b].at(h) == '1')
            ans++;
    }
    if(pass)
        return ans;
    else
        return -1;
}

int main()
{
    N[0] = "1110111";
    N[1] = "0010010";
    N[2] = "1011101";
    N[3] = "1011011";
    N[4] = "0111010";
    N[5] = "1101011";
    N[6] = "1101111";
    N[7] = "1010010";
    N[8] = "1111111";
    N[9] = "1111011";

    cin>>n>>k;
    string s[n];
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<10;i++)
    {
        if(check(s[n-1],i)!=-1)
            dp[n-1][check(s[n-1],i)] = i+1;
    }
    for(i=0;i<2000;i++)
    {
        dp[n-1][i]--;
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<10;j++)
        {
            int val = check(s[i],j);
            if(val != -1)
            {
                for(run=0;run<=2000;run++)
                {
                    int value = dp[i+1][run];
                    if(value != -1)
                    {
                        dp[i][run+val] = j +1;
                    }
                }
            }
        }
        for(j=0;j<=2000;j++)
            dp[i][j]--;
    }
    if(dp[0][k] == -1)
        cout<<-1;
    else
    {
        for(i=0;i<n;i++)
        {
            cout<<dp[i][k];
            int val = check(s[i],dp[i][k]);
            k-=val;
        }
    }
    return 0;
}