#include <bits/stdc++.h>
using namespace std;
char v[100003];
int fv[30];
bool slv (int n, int k, int pz, char c)
{
    ++fv[c-'a'];
    int ram=n-pz;
    for(int i=0;i<=26;++i)
        ram-=k-((fv[i]+k-1)%k+1);
    --fv[c-'a'];
    if(ram>=0)
        return true;
    return false;
}
vector<char>idk;
int main ()
{
    ios_base::sync_with_stdio(0);
    int t,m,i,j,k=0,s=0,n,mn,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<=26;++i)
            fv[i]=0;
        cin>>(v+1);
        if(n%k)
        {
            cout<<-1<<'\n';
            continue;
        }
        int pz=-1;
        char c=-1;
        for(i=1;i<=n;++i)
        {
            for(char cc='z';cc>v[i];--cc)
            {
                if(slv(n,k,i,cc))
                {
                    pz=i;
                    c=cc;
                }
            }
            ++fv[v[i]-'a'];
        }
        int ok=1;
        for(i=0;i<=26;++i)
            if(fv[i]%k)
                ok=0;
        if(ok==1)
        {
            cout<<(v+1);
            cout<<'\n';
            continue;
        }
        for(i=0;i<=26;++i)
            fv[i]=0;
        for(i=1;i<pz;++i)
            ++fv[v[i]-'a'];
        ++fv[c-'a'];
        v[pz]=c;
        idk.clear();
        for(i=0;i<=26;++i)
        {
            while(fv[i]%k)
            {
                idk.push_back('a'+i);
                ++fv[i];
            }
        }
        for(i=1;i<=pz;++i)
            cout<<v[i];
        while(idk.size()<n-pz)
            idk.push_back('a');
        sort(idk.begin(),idk.end());
        for(i=0;i<idk.size();++i)
            cout<<idk[i];
        cout<<'\n';
    }
}