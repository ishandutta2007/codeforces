#include <bits/stdc++.h>

using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
bool verif (int a, int b)
{
    if(cmmdc(a,b)==1)
        return true;
    return false;
}
int v[100003],nxt[100003],pr[100003];
queue<int>q;
vector<int>rz;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            nxt[i]=i+1,pr[i]=i-1;
        pr[1]=n;
        nxt[n]=1;
        for(i=2;i<=n;++i)
            q.push(i);
        q.push(1);
        rz.clear();
        while(!q.empty())
        {
            int pz=q.front();
            if(pz==pr[pz])
            {
                if(v[pz]==1)
                {
                    rz.push_back(pz);
                    break;
                }
                else
                    break;
            }
            q.pop();
            if(verif(v[pz],v[pr[pz]]))
            {
                rz.push_back(pz);
                nxt[pr[pz]]=nxt[pz];
                pr[nxt[pz]]=pr[pz];
                if(!q.empty())
                    if(q.front()==nxt[pz])
                        q.pop();
                q.push(nxt[pz]);
            }
        }
        while(!q.empty())
            q.pop();
        cout<<rz.size()<<' ';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}