#include <iostream>

using namespace std;
char v[1003];
int main()
{
    int a,b,c,d,k,i,j,t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int mx=0;
        int lstpz=0;
        for(i=1;i<=n;++i)
            if(v[i]=='1')
                lstpz=i;
        if(lstpz==0)
        {
            cout<<n<<'\n';
            continue;
        }
        mx=lstpz*2;
        for(i=1;i<=n;++i)
            if(v[i]=='1')
                mx=max(mx,i-1+2*(lstpz-i+1));
        for(i=1;i<=n/2;++i)
            swap(v[i],v[n-i+1]);
        for(i=1;i<=n;++i)
            if(v[i]=='1')
                lstpz=i;
        mx=max(mx,lstpz*2);
        for(i=1;i<=n;++i)
            if(v[i]=='1')
                mx=max(mx,i-1+2*(lstpz-i+1));
        cout<<mx<<'\n';
    }
    return 0;
}