#include <bits/stdc++.h>
using namespace std;
char v[3][200003];
int cnt[3][2];
int vl[3];
int main()
{
    ios_base::sync_with_stdio(false);
    long long q,t,m,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>v[0]>>v[1]>>v[2];
        for(i=0;i<=2;++i)
            cnt[i][0]=cnt[i][1]=0;
        for(i=0;i<=2;++i)
        {
            for(j=0;j<2*n;++j)
            {
                ++cnt[i][v[i][j]-'0'];
            }
        }
        int ch=0;
        for(i=0;i<=2;++i)
        {
            if(cnt[i][0]>cnt[i][1])
                vl[i]=0;
            else
                vl[i]=1;
        }
        int a=0,b=1;
        if(vl[a]!=vl[b])
        {
            if(vl[0]==vl[2])
                a=0,b=2;
            else if(vl[1]==vl[2])
                a=1,b=2;
        }
        ch=vl[a];
        ch=1-ch;
        int i=0,j=0;
        while(i<2*n || j<2*n)
        {
            if(i==2*n)
            {
                cout<<v[b][j++];
            }
            else if(j==2*n)
            {
                cout<<v[a][i++];
            }
            else
            {
                if(v[a][i]-'0'==ch || v[b][j]-'0'==ch)
                {
                    cout<<ch;
                    if(v[a][i]-'0'==ch)
                        ++i;
                    if(v[b][j]-'0'==ch)
                        ++j;
                }
                else
                {
                    cout<<1-ch;
                    if(v[a][i]-'0'!=ch)
                        ++i;
                    if(v[b][j]-'0'!=ch)
                        ++j;
                }

            }
        }
        cout<<'\n';
    }
	return 0;
}