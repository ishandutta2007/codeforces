#include<bits/stdc++.h>

using namespace std;

int n;
int lmao[500005][3], x, y; 
string s;

signed main ()
{
    cin>>n; 
    for(int i=1; i<=n; i++)
    {
        cin>>s>>x>>y; 
        if(s[0]=='+')
        {
            lmao[i][0]=1;
        } 
        else 
        {
            lmao[i][0]=0;
        } 
        if(x>y) 
        {
            swap(x, y);
        } 
        lmao[i][1]=x; 
        lmao[i][2]=y;
    }
    int max1=lmao[1][1], max2=lmao[1][2]; 
    for(int i=1; i<=n; i++) 
    {
        if(lmao[i][0]==1) 
        {
            if(lmao[i][1]>max1)
            {
                max1=lmao[i][1]; 
            }
            if(lmao[i][2]>max2) 
            {
                max2=lmao[i][2];
            }
        }
        else
        {
            if(lmao[i][1]>=max1&&lmao[i][2]>=max2) 
            {
                cout<<"YES\n"; 
            }
            else 
            {
                cout<<"NO\n";
            }
        }
    }
}