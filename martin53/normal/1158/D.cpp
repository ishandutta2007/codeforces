#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n;

pair<int,int> inp[nmax];

int outp[nmax];
bool been[nmax];

long long area(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    long long x1=b.first-a.first,y1=b.second-a.second;
    long long x2=c.first-b.first,y2=c.second-b.second;

    return x1*y2-x2*y1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i].first>>inp[i].second;

    int mini=1;
    for(int i=2;i<=n;i++)
        if(inp[i].first<inp[mini].first)mini=i;

    outp[1]=mini;
    been[mini]=1;

    for(int i=1;i<=n-2;i++)
    {
        char c;
        cin>>c;

        int lst=outp[i];

        int cur=-1;

        for(int j=1;j<=n;j++)
            if(been[j]==0)
            {
                if(cur==-1)cur=j;
                else
                {
                    if(c=='L'&&area(inp[j],inp[lst],inp[cur])<0)cur=j;
                    if(c=='R'&&area(inp[j],inp[lst],inp[cur])>0)cur=j;
                }
            }
        outp[i+1]=cur;
        been[cur]=1;
    }

    for(int i=1;i<=n;i++)
        if(been[i]==0)outp[n]=i;

    for(int i=1;i<=n;i++)
        cout<<outp[i]<<" ";cout<<endl;

    return 0;
}