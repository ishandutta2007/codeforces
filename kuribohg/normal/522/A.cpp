#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<iterator>
using namespace std;
int n,N,w[510][510],ans;
string name1,temp,name2;
map<string,int> M;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name1>>temp>>name2;
        int len1=name1.length();
        for(int i=0;i<len1;i++)
            if(name1[i]>='a'&&name1[i]<='z') name1[i]=name1[i]-'a'+'A';
        int len2=name2.length();
        for(int i=0;i<len2;i++)
            if(name2[i]>='a'&&name2[i]<='z') name2[i]=name2[i]-'a'+'A';
        if(!M.count(name1)) M[name1]=++N;
        if(!M.count(name2)) M[name2]=++N;
        w[M[name1]][M[name2]]=1;
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(!w[i][j]) w[i][j]=-1000000000;
    for(int i=1;i<=N;i++) w[i][i]=0;
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                w[i][j]=max(w[i][j],w[i][k]+w[k][j]);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            ans=max(ans,w[i][j]);
    printf("%d\n",ans+1);
    return 0;
}