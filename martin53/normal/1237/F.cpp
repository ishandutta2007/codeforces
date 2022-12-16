#include<bits/stdc++.h>
using namespace std;

const int nmax=3600+42,mod=998244353;

bool blocked_row[nmax],blocked_column[nmax];

int h,w,n;

int pointer_row;
int pointer_column;

int rows[nmax][nmax],columns[nmax][nmax];

int c[nmax][nmax];

int ask_c(int n_,int k_)
{
    if(n_<k_||n_<0||k_<0)return 0;
    return c[n_][k_];
}

int fact[nmax];

int main()
{
    scanf("%i%i%i",&h,&w,&n);

    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;

        scanf("%i%i%i%i",&x1,&y1,&x2,&y2);

        blocked_row[x1]=1;
        blocked_row[x2]=1;

        blocked_column[y1]=1;
        blocked_column[y2]=1;
    }

    for(int i=1;i<=h;i++)
        if(blocked_row[i]==0)pointer_row++;

    for(int j=1;j<=w;j++)
        if(blocked_column[j]==0)pointer_column++;

    rows[0][0]=1;
    for(int i=1;i<=h;i++)
    {
        rows[i][0]=1;

        for(int groups=1;groups*2<=i;groups++)
        {
            rows[i][groups]=rows[i-1][groups];

            if(i>=2&&blocked_row[i]==0&&blocked_row[i-1]==0)
            {
                rows[i][groups]=(rows[i][groups]+rows[i-2][groups-1])%mod;
            }

            //cout<<i<<" "<<groups<<" -> rows "<<rows[i][groups]<<endl;
        }
    }

    columns[0][0]=1;
    for(int j=1;j<=w;j++)
    {
        columns[j][0]=1;

        for(int groups=1;groups*2<=j;groups++)
        {
            columns[j][groups]=columns[j-1][groups];

            if(j>=2&&blocked_column[j]==0&&blocked_column[j-1]==0)
            {
                columns[j][groups]=(columns[j][groups]+columns[j-2][groups-1])%mod;
            }

            //cout<<j<<" "<<groups<<" -> columns "<<columns[j][groups]<<endl;
        }
    }

    for(int i=0;i<=max(w,h);i++)
        for(int j=0;j<=i;j++)
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

    fact[0]=1;
    for(int i=1;i<=max(w,h);i++)
        fact[i]=1LL*fact[i-1]*i%mod;

    long long outp=0;

    for(int i=0;i<=pointer_row;i++)
        for(int j=0;j<=pointer_column;j++)
            if(rows[h][i]&&columns[w][j])
            {
                long long cur=rows[h][i];
                cur=cur*columns[w][j]%mod;

                cur=cur*ask_c(pointer_column-2*j,i)%mod;
                cur=cur*ask_c(pointer_row-2*i,j)%mod;

                cur=cur*fact[i]%mod;
                cur=cur*fact[j]%mod;

                //cout<<i<<" "<<j<<" -> "<<cur<<endl;

                outp=(outp+cur)%mod;
            }

    printf("%lld\n",outp);
    return 0;
}