#include <bits/stdc++.h>
using namespace std;
int v[501],st[501],vf1[501][501];
int main()
{
#ifdef HOME
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif // HOME
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,vf=0,i,cnt=0,j,max1=-1,x,y;
    char c;
    cin>>n>>ws;
    for(i=1; i<=n; i++)
    {
        cin>>c;
        if(c=='(')
            v[i]=1;
        else
            v[i]=-1;
    }
    for(i=0; i<n; i++)
    {
        vf=0;
        for(j=n-i+1; j<=n; j++)
        {
            st[++vf]=j;
            if(v[st[vf]]+v[st[vf-1]]==0&&v[st[vf]]==-1)
                vf-=2;
        }
        for(j=1; j<=n-i; j++)
        {
            st[++vf]=j;
            if(v[st[vf]]+v[st[vf-1]]==0&&v[st[vf]]==-1)
                vf-=2;
        }
        if(vf==0)
        {
            cnt++;
            for(j=n-i+1; j<=n; j++)
            {
                st[++vf]=j;
                if(v[st[vf]]+v[st[vf-1]]==0&&v[st[vf]]==-1)
                {
                    if(vf!=2)
                    {
                        vf1[st[vf]][st[vf-1]]++;
                        vf1[st[vf-1]][st[vf]]++;
                    }
                    vf-=2;
                }
            }
            for(j=1; j<=n-i; j++)
            {
                st[++vf]=j;
                if(v[st[vf]]+v[st[vf-1]]==0&&v[st[vf]]==-1)
                {
                    if(vf!=2)
                    {
                        vf1[st[vf]][st[vf-1]]++;
                        vf1[st[vf-1]][st[vf]]++;
                    }
                    vf-=2;
                }
            }
        }
        else if(vf==2&&v[st[vf]]+v[st[vf-1]]==0)
        {
            vf1[st[vf]][st[vf-1]]++;
            vf1[st[vf-1]][st[vf]]++;
        }
        else if(vf==4&&v[st[2]]==-1&&v[st[3]]==1)
        {
            //if(max(st[vf],st[1])==10&&min(st[vf],st[1])==5)
            //cout<<i<<" ";
            vf1[st[vf]][st[1]]++;
            vf1[st[1]][st[vf]]++;
        }
        /*if(i==11)
        {
         cout<<'\n';
         for(j=1;j<=vf;j++)
            cout<<st[j]<<" ";
        }*/
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(v[i]==v[j])
            {
                if(max1<vf1[i][j]+cnt)
                {
                    max1=vf1[i][j]+cnt;
                    x=i;
                    y=j;
                }
            }
            else
            {
                if(max1<vf1[i][j])
                {
                    max1=vf1[i][j];
                    x=i;
                    y=j;
                }
            }
    /*for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(v[i]==v[j])
                {
                cout<<i<<" "<<j<<" "<<vf1[i][j]+cnt<<'\n';}
            else
               {
                cout<<i<<" "<<j<<" "<<vf1[i][j]<<'\n';}*/
    cout<<max1<<'\n'<<min(x,y)<<" "<<max(x,y);
    return 0;
}