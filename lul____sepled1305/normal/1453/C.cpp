#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n,i,j,k;
    cin>>n;
    string s[n];
    for(i=0;i<n;i++)
        cin>>s[i];
 
    //0 mini 1 maxi -1 if not exists
 
    for(k=0;k<10;k++)
    {
        int mini_row = 1e9, mini_col = 1e9, maxi_row = -1, maxi_col = -1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j]-'0' == k)
                {
                    mini_row = min(mini_row,i);
                    maxi_row = max(maxi_row,i);
                    mini_col = min(mini_col,j);
                    maxi_col = max(maxi_col,j);
                }
            }
        }
        if(mini_row == 1e9)
        {
            cout<<"0 ";
            continue;
        }
        int maxi = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i][j]-'0' != k)
                    continue;
                maxi = max(maxi,(i-mini_row)*max(j,n-1-j));
                maxi = max(maxi,(maxi_row-i)*max(j,n-1-j));
                maxi = max(maxi,(j-mini_col)*max(i,n-1-i));
                maxi = max(maxi,(maxi_col-j)*max(i,n-1-i));
            }
        }
        cout<<maxi<<' ';
    }
    cout<<endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}