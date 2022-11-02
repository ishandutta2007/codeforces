#include<bits/stdc++.h>
using namespace std;

int n,m,i;

int main()
{
    cin>>n>>m;
    char a[n][m];
    for(i=0;i<n;i++)
        cin>>a[i];
    if(n>=4 && m>=4)
        cout<<-1;
    else if(n==1 || m==1)
        cout<<0;
    else if(n==2)
    {
        int so = 0, se = 0;
        for(i=0;i<m;i+=2)
        {
            if(a[0][i] == a[1][i])
                se++;
            else
                so++;
        }
        for(i=1;i<m;i+=2)
        {
            if(a[0][i] == a[1][i])
                so++;
            else
                se++;
        }
        cout<<min(so,se)<<"\n";
    }
    else if(n==3)
    {
        int soo = 0, see = 0, soe = 0, seo = 0;
        for(i=0;i<m;i+=2)
        {
            if(a[0][i] == a[1][i] && a[2][i] == a[1][i])
                soo++;
            if(a[0][i] == a[1][i] && a[2][i] != a[1][i])
                soe++;
            if(a[0][i] != a[1][i] && a[2][i] == a[1][i])
                seo++;
            if(a[0][i] != a[1][i] && a[2][i] != a[1][i])
                see++;
        }
        for(i=1;i<m;i+=2)
        {
            if(a[0][i] == a[1][i] && a[2][i] == a[1][i])
                see++;
            if(a[0][i] == a[1][i] && a[2][i] != a[1][i])
                seo++;
            if(a[0][i] != a[1][i] && a[2][i] == a[1][i])
                soe++;
            if(a[0][i] != a[1][i] && a[2][i] != a[1][i])
                soo++;
        }
        cout<<m - max(max(soe,seo),max(soo,see));
    }
    else
    {
        int soo = 0, see = 0, soe = 0, seo = 0;
        for(i=0;i<n;i+=2)
        {
            if(a[i][0] == a[i][1] && a[i][2] == a[i][1])
                soo++;
            if(a[i][0] == a[i][1] && a[i][2] != a[i][1])
                soe++;
            if(a[i][0] != a[i][1] && a[i][2] == a[i][1])
                seo++;
            if(a[i][0] != a[i][1] && a[i][2] != a[i][1])
                see++;
        }
        for(i=1;i<n;i+=2)
        {
            if(a[i][0] == a[i][1] && a[i][2] == a[i][1])
                see++;
            if(a[i][0] == a[i][1] && a[i][2] != a[i][1])
                seo++;
            if(a[i][0] != a[i][1] && a[i][2] == a[i][1])
                soe++;
            if(a[i][0] != a[i][1] && a[i][2] != a[i][1])
                soo++;
        }
        cout<<n - max(max(soe,seo),max(soo,see));
    }
    return 0;
}