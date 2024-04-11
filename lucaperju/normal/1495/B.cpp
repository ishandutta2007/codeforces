#include <bits/stdc++.h>

using namespace std;
int v[100003],st[100003],dr[100003],mst[100003],mdr[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    st[1]=1;
    for(i=2;i<=n;++i)
    {
        if(v[i]<v[i-1])
            st[i]=1;
        else
            st[i]=1+st[i-1];
    }
    dr[n]=1;
    for(i=n-1;i>=1;--i)
    {
        if(v[i]<v[i+1])
            dr[i]=1;
        else
            dr[i]=1+dr[i+1];
    }
    for(i=1;i<=n;++i)
        mst[i]=max(max(st[i],mst[i-1]),dr[i]);
    for(i=n;i>=1;--i)
        mdr[i]=max(max(st[i],mdr[i+1]),dr[i]);
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(st[i]==dr[i] && st[i]%2==1)
        {
            if(max(mst[i-1],mdr[i+1])<st[i])
                ++cnt;
        }
    }
    cout<<cnt;
	return 0;
}