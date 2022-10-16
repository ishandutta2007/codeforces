#include <iostream>

using namespace std;
int v[200003],fv[200003],z[200003];
bool ok[200003];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        fv[v[i]]++;
    }
    for(i=1,j=0;i<=n;i++)
    {
        if(fv[i]==0)
            z[++j]=i;
    }
    cout<<j<<'\n';
    j=1;
    for(i=1;i<=n;i++)
    {
        if(fv[v[i]]>=2 && z[j]<v[i] || fv[v[i]]>=2 && ok[v[i]]==1)
        {
            fv[v[i]]--;
            v[i]=z[j];
            fv[z[j]]++;
            j++;
        }
        else
        if(fv[v[i]]>=2)
            ok[v[i]]=1;
        cout<<v[i]<<' ';
    }
    return 0;
}