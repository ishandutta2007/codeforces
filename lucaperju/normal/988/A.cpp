#include <iostream>

using namespace std;
int fv[105],v[105],poz[105];
int main()
{
    int n,k,cnt=0,i;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(fv[v[i]]==0)
            cnt++;
        poz[v[i]]=i;
        fv[v[i]]++;
    }
    if(cnt>=k)
        cout<<"YES"<<'\n';
    else
        cout<<"NO";
    if(cnt>=k)
    {
        for(i=1;i<=100,k>=1;++i)
        {
            if(fv[i])
            {
                cout<<poz[i]<<' ';
                k--;
            }
        }
    }
    return 0;
}