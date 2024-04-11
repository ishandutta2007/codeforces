#include<bits/stdc++.h>
using namespace std;
const int LIM=(1<<19)+42,mod=1e9+7;
string inp;
int/*number*/tree[26][LIM];
int mult[LIM];
int query(int letter,int l,int r)
{
    int ans=(tree[letter][r]-1LL*mult[r-l+1]*(l?tree[letter][l-1]:0))%mod;
    return (ans+mod)%mod;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int n,q;
cin>>n>>q;
cin>>inp;
mult[0]=1;
for(int i=1;i<LIM;i++)
    mult[i]=(10LL*mult[i-1])%mod;

for(int le=0;le<26;le++)
    for(int pos=0;pos<n;pos++)
        {
        tree[le][pos]=(inp[pos]=='a'+le);
        if(pos)tree[le][pos]=(10LL*tree[le][pos-1]+tree[le][pos])%mod;
        }
int x,y,len;
for(int i=1;i<=q;i++)
{
    cin>>x>>y>>len;
    x--;
    y--;
    bool ok=1;
    for(int j=0;j<26;j++)
    {
        bool now=0;
        for(int k=0;k<26;k++)
            if(query(j,x,x+len-1)==query(k,y,y+len-1)){now=1;break;}
        if(now==0){ok=0;break;}
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
}
return 0;
}