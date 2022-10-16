#include <bits/stdc++.h>

using namespace std;
char v[2000005];
int dst[11][11];
int main()
{
    ios_base::sync_with_stdio(0);
    long long k,t,i,j=0,cnt=1,n,m,is,js,ib,jb,s=0,mx=0,cur=0,q;
    cin>>v;
    n=strlen(v);
    for(int x=0;x<=9;++x)
    {
        for(int y=0;y<=9;++y)
        {
            for(i=0;i<=9;++i)
                for(j=0;j<=9;++j)
                {
                    int mn=999999;
                    for(int catx=0;catx<=10;++catx)
                        for(int caty=0;caty<=10;++caty)
                        {
                            if((i+catx*x+caty*y)%10==j && (catx!=0 || caty!=0))
                                mn=min(mn,catx+caty);
                        }
                    if(mn==999999)
                        dst[i][j]=-1;
                    else
                        dst[i][j]=mn;
                }
            s=0;
            int okcur=0;
            for(i=1;i<n;++i)
            {
                if(dst[v[i-1]-'0'][v[i]-'0']!=-1)
                    s+=dst[v[i-1]-'0'][v[i]-'0'];
                else
                {
                    cout<<-1<<' ';
                    okcur=1;
                    break;
                }
            }
            if(okcur)
                continue;
            cout<<s-n+1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}