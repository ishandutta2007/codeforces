#include <bits/stdc++.h>

using namespace std;
int v[55],fv[2];
char cur[55];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,q,i,j;
    cin>>q;
    while(q--)
    {
      cin>>n;
      fv[0]=fv[1]=0;
      for(i=1;i<=n;++i)
      {
        cin>>cur;
        v[i]=strlen(cur);
        for(j=0;j<v[i];++j)
        {
          if(cur[j]=='0')
            ++fv[0];
          else
            ++fv[1];
        }
      }
      int cnt=0;
      for(i=1;i<=n;++i)
        if(v[i]&1)
          ++cnt;
      int vlc=fv[0]%2+fv[1]%2;
      vlc-=cnt;
      cout<<n-min(max(vlc,0),1)<<'\n';
    }
    return 0;
}