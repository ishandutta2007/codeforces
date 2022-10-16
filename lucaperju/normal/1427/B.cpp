#include <bits/stdc++.h>
using namespace std;
char v[100003];
vector<int>gr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n,i,j,s=0,rz=0;
    cin>>t;
    while(t--)
    {
        int k;
        int cntl=0;
        cin>>n>>k;
        gr.clear();
        for(i=1;i<=n;++i)
            cin>>v[i];
        int cntc=-1;
        rz=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='L')
                ++cntl;
            if(v[i]=='W')
            {
                if(cntc>0)
                    gr.push_back(cntc);
                cntc=0;
                if(v[i-1]=='W')
                    rz+=2;
                else
                    ++rz;
            }
            else
            {
                if(cntc!=-1)
                    ++cntc;
            }
        }
        if(cntl==n)
        {
            cout<<max(0,k*2-1)<<'\n';
            continue;
        }
        k=min(k,cntl);
        sort(gr.begin(),gr.end());
        for(i=0;i<gr.size();++i)
        {
            if(gr[i]>k)
                break;
            k-=gr[i];
            rz+=gr[i]*2+1;
        }
        cout<<rz+k*2<<'\n';
    }
}