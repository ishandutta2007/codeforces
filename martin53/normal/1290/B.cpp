#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
string inp;

int seen[nmax][26];
string query()
{
    int l,r;
    cin>>l>>r;
    if(l==r)return "YES";

    if(inp[l-1]!=inp[r-1])return "YES";
    int on=0;
    for(int j=0;j<26;j++)
    {
        int current=seen[r][j]-seen[l-1][j];
        if(current)on++;
    }

    if(on<=2)return "NO";
    return "YES";
}
int main()
{
    cin>>inp;
    for(int i=1;i<=inp.size();i++)
        for(int j=0;j<26;j++)
            seen[i][j]=seen[i-1][j]+(inp[i-1]=='a'+j);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cout<<query()<<"\n";
    }
    return 0;
}