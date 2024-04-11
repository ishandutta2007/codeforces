#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,len[110];
string str[110],P;
int S[110];
bool del[110];
bool check(string str,string P)
{
    int len=str.size();
    if(len!=P.size()) return false;
    for(int i=0;i<len;i++)
        if(P[i]!='?'&&str[i]!=P[i]) return false;
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>str[i];
    for(int i=1;i<=m;i++) cin>>S[i];
    for(int i=1;i<=n;i++) len[i]=str[i].size();
    for(int i=1;i<=m;i++)
        if(len[S[i]]!=len[S[1]]) {puts("No");return 0;}
    P=str[S[1]];
    for(int i=0;i<len[S[1]];i++)
    {
        for(int j=1;j<=m;j++)
            if(str[S[1]][i]!=str[S[j]][i]) P[i]='?';
    }
    for(int i=1;i<=n;i++)
        del[i]=check(str[i],P);
    bool ok=true;
    for(int i=1;i<=n;i++)
    {
        bool sok=false;
        for(int j=1;j<=m;j++)
            if(i==S[j]) sok=true;
        if(sok&&!del[i]) {puts("No");return 0;}
        else if(!sok&&del[i]) {puts("No");return 0;}
    }
    cout<<"Yes"<<endl<<P<<endl;
    return 0;
}