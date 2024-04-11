#include <bits/stdc++.h>
using namespace std;
int v[100003];
int fv[100003];
int cnt;
int prevv[21][100003];
void addnumber (int a)
{
    for(int i=2;i*i<=a;++i)
    {
        if(a%i==0)
        {
            ++fv[i];
            if(fv[i]==2)
                ++cnt;
            while(a%i==0)
                a/=i;
        }
    }
    if(a!=1)
    {
        ++fv[a];
        if(fv[a]==2)
            ++cnt;
    }
}
void removenumber (int a)
{
    for(int i=2;i*i<=a;++i)
    {
        if(a%i==0)
        {
            --fv[i];
            if(fv[i]==1)
                --cnt;
            while(a%i==0)
                a/=i;
        }
    }
    if(a!=1)
    {
        --fv[a];
        if(fv[a]==1)
            --cnt;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q,t,m,i,j,n;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    j=1,i=0;
    for(i=1;i<=n;++i)
    {
        addnumber(v[i]);
        while(cnt>0)
            removenumber(v[j++]);
        prevv[0][i]=j-1;
    }
    for(int put=1;put<=20;++put)
    {
        for(i=1;i<=n;++i)
        {
            prevv[put][i]=prevv[put-1][prevv[put-1][i]];
        }
    }
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        int cnt=1;
        for(int put=20;put>=0;--put)
        {
            if(prevv[put][b]>=a)
            {
                cnt+=(1<<put);
                b=prevv[put][b];
            }
        }
        cout<<cnt<<'\n';
    }
	return 0;
}