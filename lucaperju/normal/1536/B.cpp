#include <bits/stdc++.h>

using namespace std;
char v[1003];
char vc[103];
int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>(v+1);
        v[0]=-1;
        int msk;
        for(msk=0;1;++msk)
        {
            int ok=0;
            int cmsk=msk;
            int idfk=0;
            if(cmsk%27==0)
                idfk=1;
            while(cmsk)
            {
                if(cmsk%27==0)
                    idfk=1;
                cmsk/=27;
            }
            if(idfk)
                continue;
            for(j=n;j>=1;--j)
            {
                int okk=1;
                int cmsk=msk,cnt=0;
                while(cmsk)
                {
                    if(v[j-cnt]-'a'+1!=cmsk%27)
                    {
                        okk=0;
                        break;
                    }
                    ++cnt;
                    cmsk/=27;
                }
                ok=max(ok,okk);
            }
            if(!ok)
                break;
        }
        j=0;
        while(msk)
        {
            vc[++j]=msk%27+'a'-1;
            msk/=27;
        }
        for(i=j;i>=1;--i)
            cout<<vc[i];
        cout<<'\n';
    }
    return 0;
}