/**COME HOME QUICKLY, ONII-CHAN!**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,m,i,j,col=0,row=0;
        cin>>n>>m;
        char s[n][m];
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>s[i][j];
        for(i=0;i<m;i++)
        {
            bool pass = true;
            for(j=0;j<n;j++)
            {
                if(s[j][i]=='1')
                    pass = false;
            }
            if(pass)
                col++;
        }
        for(i=0;i<n;i++)
        {
            bool pass = true;
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='1')
                    pass = false;
            }
            if(pass)
                row++;
        }
        int ans = min(row,col);
        if(ans%2)
            cout<<"Ashish\n";
        else
            cout<<"Vivek\n";
    }
    return 0;
}