#include <bits/stdc++.h>
#define int long long
using namespace std;

string f[10005], l[10005];
int ans[10005];
string fib[10005], s, s1;
int n;
int pi[105];

void init()
{
    pi[1]=0;
    for(int i=2; i<(int)s1.size(); i++)
    {
        pi[i]=pi[i-1];
        while(pi[i]!=0&&s1[pi[i]+1]!=s1[i])
        {
            pi[i]=pi[pi[i]];
        }
        if(s1[pi[i]+1]==s1[i]) pi[i]++;
    }
}

int kmp(string x)
{
    int anss=0;
    int now=0;
    for(int i=0; i<(int)x.size(); i++)
    {
        if(x[i]==s1[now+1])
        {
            now++;
            if(now==(int)s.size())
            {
                now=pi[now];
                anss++;
            }
        }
        else
        {
            while(now!=0&&x[i]!=s1[now+1])
            {
                now=pi[now];
            }
            if(x[i]==s1[now+1]) now++;
        }
    }
    return anss;
}

signed main()
{
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        int x, y;
        cin>>x>>y;
        if(x-y==1) cout<<"NO\n";
        else cout<<"YES\n";
    }
}