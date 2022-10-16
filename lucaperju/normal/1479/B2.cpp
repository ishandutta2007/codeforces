#include <bits/stdc++.h>
using namespace std;
int v[100003];
int a[100003],b[100003],fv[100003];
vector<int>vc;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,m,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(fv[v[i]]==0)
        {
            ++cnt;
            fv[v[i]]=1;
            vc.push_back(v[i]);
        }
        else
        {
            if(v[i-1]!=v[i])
            {
                for(j=0;j<vc.size();++j)
                    fv[vc[j]]=0;
                vc.clear();
                fv[v[i]]++;
                fv[v[i-1]]++;
                vc.push_back(v[i]);
                vc.push_back(v[i-1]);
            }
        }
    }
    cout<<cnt;
    return 0;
}