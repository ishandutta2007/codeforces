#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

string a[10][1010];
int n;
int main()
{
    read(n);
    a[0][1]="1";
    for (int i=1;i<=n;i++)
    {
        int ha=1<<(i-1);
        for (int j=1;j<=ha;j++)
        {
            a[i][j]=a[i-1][j]+a[i-1][j];
        }
        for (int j=1;j<=ha;j++)
        {
            for (int k=1;k<=ha;k++)
            if (a[i-1][j][k-1]=='0')    a[i][ha+j]+='1';else a[i][ha+j]+='0';
            a[i][ha+j]+=a[i-1][j];
        }
    }
    for (int i=1;i<=(1<<n);i++)
    {
        for (int j=1;j<=(1<<n);j++)
            if (a[n][i][j-1]=='0')  printf("+");else printf("*");
        printf("\n");
    }
    return 0;
}