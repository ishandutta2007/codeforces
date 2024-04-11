#include <bits/stdc++.h>

using namespace std;
int k;
vector<int>v[100003];
char patterns[100003][5];
map<long long,int>mp[17];
long long gethash (char vc[], int mask)
{
    long long s=0;
    for(int i=1;i<=k;++i)
    {
        if(!(mask&1))
            s=s*29LL+(vc[i]-'a'+1);
        mask>>=1;
    }
    return s;
}
char str/*ambei*/[5];
int rz[100003],viz[100003],pzf[100003];
int idk;
void dfs (int pz)
{
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
            dfs(v[pz][i]);
    }
    rz[++idk]=pz;
    pzf[pz]=idk;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,s;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        cin>>(patterns[i]+1);
        s=0;
        int p=1;
        for(j=1;j<=k;++j)
        {
            if(patterns[i][j]=='_')
                s+=p;
            p<<=1;
        }
        mp[s][gethash(patterns[i],s)]=i;
    }
    for(i=1;i<=m;++i)
    {
        cin>>(str+1);
        int a;
        cin>>a;
        for(j=1;j<=k;++j)
        {
            if(patterns[a][j]!='_' && patterns[a][j]!=str[j])
            {
                cout<<"NO\n";
                return 0;
            }
        }
        for(int mask=0;mask<(1<<k);++mask)
        {
            int val=mp[mask][gethash(str,mask)];
            if(val && val!=a)
                v[a].push_back(val);
        }
    }
    for(i=1;i<=n;++i)
    {
        if(!viz[i])
            dfs(i);
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++j/*i bruh*/)
        {
            if(pzf[i]<pzf[v[i][j]])
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(i=n;i>=1;--i)
        cout<<rz[i]<<' ';
    return 0;
}