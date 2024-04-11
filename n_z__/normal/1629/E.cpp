#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<bool>>a(n+2,vector<bool>(n+2));
        int ans=0;
        for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            int q;
            cin>>q;
            if(!a[x-1][y]&&!a[x][y-1]&&!a[x+1][y]&&!a[x][y+1])ans^=q,a[x-1][y]=a[x][y-1]=a[x+1][y]=a[x][y+1]=1;
        }
		cout<<ans<<endl;
    }
}