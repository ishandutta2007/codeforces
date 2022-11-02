#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c;
char A[1010];
string f(string s)
{
    s[s.size()-1]++;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='z'+1)
        {
            s[i]='a';
            if(i)s[i-1]++;
            else s='a'+s;
        }
    }
    return s;
}
bool g(string s)
{
    int m=s.size();
    for(i=0;i<=n-m;i++)
    {
        bool flag=true;
        for(j=0;j<m;j++)if(s[j]!=A[i+j])flag=false;
        if(flag)return true;
    }
    return false;
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);scanf("%s", &A);
        string s="a";
        while(1)
        {
            if(!g(s))
            {
                cout<<s<<"\n";break;
            }s=f(s);
        }
    }
}