#include <iostream>
using namespace std;
int main()
{
      int ans=0;
      int n;
      cin>>n;
      for (int i=0;i<n;i++)
      {
            int p,v,t;
            cin>>p>>v>>t;
            if (p>0&&v>0)
                  ans++;
            else if (p>0 && t>0)
                  ans++;
            else if (v>0&&t>0)
                  ans++;
      }
      cout<<ans;
}