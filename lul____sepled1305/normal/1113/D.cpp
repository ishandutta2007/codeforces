#include<bits/stdc++.h>
using namespace std;
int a,c,b,i,j,k,l,n,loop;
char s[5005];
char g[5005];
int main()
{
    scanf("%s",&s);
    while(s[i]!='\0')
    {
        if(s[i]!=s[0] &&i>0)
        {
            k++;
            //cout<<i;
        }
        i++;
    }
    //cout<<k;
    if(k==0)
    {
        cout<<"Impossible";
    }
    else if(i%2==1)
    {
        if(k!=1)
        cout<<2;
        else if(k==1)
        {
            cout<<"Impossible";
        }
    }
    else
    {
        for(k=0;k<i;k++)
        {
            int che=0,ni=0;
            for(loop=0;loop<i;loop++)
            {
                if(loop<k)
                {
                    g[i-k+loop]=s[loop];
                }
                else
                    g[loop-k]=s[loop];
            }
            for(loop=0;loop<i;loop++)
            {
                if(g[loop]!=s[loop])
                {
                    che++;
                }
                if(g[loop]!=g[i-1-loop])
                {
                    ni++;
                }
            }
            if(che>0&&ni==0)
            {
                c=1;
                break;
            }
        }
        if(c==1) cout<<1;
        else cout<<2;
    }
    return 0;
}