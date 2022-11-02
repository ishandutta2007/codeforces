#include<bits/stdc++.h>
using namespace std;
int a,b,c,i,j,k,n,w,l,h,ll,aa,bb,desigx,desigy,dfs,run1,run2;
char gg[600][600];
int main()
{
    cin>>h>>w;
    for(i=1;i<=h;i++)
    {
        scanf("%s",&gg[i]);
    }
    for(i=1;i<=h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(gg[i][j]=='*')
            {
                ll++;
                if(ll==1)
                {
                    desigy=j;
                }
            }
        }
    }
    if(ll==0)
    {
        cout<<"NO";
    }
    else
    {
        ll=0;
    for(a=1;a<=h;a++)
    {
        for(b=0;b<w;b++)
        {
            if(gg[a][b]=='*' && b!=desigy)
            {
                ll++;
                if(ll==1)
                {
                    desigx=a;
                }
            }
        }
    }
    if(ll==1)
    {
        cout<<"NO";
    }
    else
    {
        ll=0;
    for(aa=1;aa<=h;aa++)
    {
        for(bb=0;bb<w;bb++)
        {
            if(gg[aa][bb]=='*' && bb != desigy && aa!= desigx)
            {
                ll++;
                break;
            }
        }
    }
    if(ll>0)
    {
        cout<<"NO";
    }
    else
    {
        if(gg[desigx][desigy]!='*')
        {
            cout<<"NO";
        }
        else if (desigy==0)
        {
            cout<<"NO";
        }
        else if (gg[desigx-1][desigy]!='*' || gg[desigx+1][desigy]!='*' || gg[desigx][desigy+1]!='*' || gg[desigx][desigy-1]!='*')
        {
            cout<<"NO";
        }
        else
        {
            if(gg[desigx][0]=='*')
            {
                run1++;
            }
            for(i=1;i<w;i++)
            {
                if(gg[desigx][i]=='*' && gg[desigx][i-1]=='.')
                {
                    run1++;
                }
            }
            //cout<<run1;
            for(i=1;i<=h;i++)
            {
                if(gg[i][desigy]=='*' && gg[i-1][desigy]!='*')
                {
                    run1++;
                }
            }
            //cout<<run1;
            if(run1 > 2)
            {
                cout<<"NO";
            }
            else
            {
                cout<<"YES";
            }
        }
    }
    }
    }
    //cout<<desigx<<desigy<<ll;
}