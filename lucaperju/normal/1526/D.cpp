#include <bits/stdc++.h>
using namespace std;
char v[100003];
int vc[100003];
char letters[]={0,'A','N','O','T'};
vector<int>pzs[5];
int aib[100003],n;
int lsb(int x)
{
    return x&-x;
}
void upd (int pz, int val)
{
    for(int i=pz;i<=n;i+=lsb(i))
        aib[i]+=val;
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
long long getinv ()
{
    long long s=0;
    for(int i=n;i>=1;--i)
    {
        s+=query(vc[i]);
        upd(vc[i],1);
    }
    for(int i=1;i<=n;++i)
        aib[i]=0;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,k;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        pzs[1].clear();
        pzs[2].clear();
        pzs[3].clear();
        pzs[4].clear();
        for(i=1;i<=n;++i)
        {
            if(v[i]=='A')
                pzs[1].push_back(i);
            else if(v[i]=='N')
                pzs[2].push_back(i);
            else if(v[i]=='O')
                pzs[3].push_back(i);
            else if(v[i]=='T')
                pzs[4].push_back(i);
        }
        int a,b,c,d;
        long long ra=1,rb=2,rc=3,rd=4,mx=0;
        for(a=1;a<=4;++a)
            for(b=1;b<=4;++b)
                for(c=1;c<=4;++c)
                    for(d=1;d<=4;++d)
                    {
                        if(a==b || a==c || a==d || b==c || b==d || c==d)
                            continue;
                        long long vlc;
                        int j=0;
                        for(i=0;i<pzs[a].size();++i)
                            vc[++j]=pzs[a][i];
                        for(i=0;i<pzs[b].size();++i)
                            vc[++j]=pzs[b][i];
                        for(i=0;i<pzs[c].size();++i)
                            vc[++j]=pzs[c][i];
                        for(i=0;i<pzs[d].size();++i)
                            vc[++j]=pzs[d][i];
                        vlc=getinv();
                        if(vlc>mx)
                        {
                            mx=vlc;
                            ra=a;
                            rb=b;
                            rc=c;
                            rd=d;
                        }
                    }
        for(i=0;i<pzs[ra].size();++i)
            cout<<letters[ra];
        for(i=0;i<pzs[rb].size();++i)
            cout<<letters[rb];
        for(i=0;i<pzs[rc].size();++i)
            cout<<letters[rc];
        for(i=0;i<pzs[rd].size();++i)
            cout<<letters[rd];
        cout<<'\n';
    }
	return 0;
}