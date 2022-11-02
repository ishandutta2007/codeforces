# include <iostream>
# include <cstdio>
# include <vector>
# include <cstring>
using namespace std;
const long long inf=0x7f7f7f7f7f7f7f7fLL;
long long f[301][301];
long long c[301][301];
int n,m,d;

void update(long long &i,const long long j)
{
    if(i>j) i=j;
}

int main()
{
    scanf("%d%d%d",&n,&m,&d);
    memset(c,0x7f,sizeof(c)); 
    memset(f,0x7f,sizeof(f));
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        for(int i=x;i<=y;i++)
        for(int j=i;j<=y;j++)
            update(c[i][j],z);
    }
    #ifdef DEBUG
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)cout<<((c[i][j]==inf)?-1:c[i][j])<<' ';
        cout<<endl;
    }
    #endif
    f[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            if(f[i][j]!=inf)
            {
                for(int k=1;k<=n-i;k++) if(c[i+1][i+k]!=inf)
                    update(f[i+k][j+k],f[i][j]+c[i+1][i+k]);
                for(int k=i+1;k<=n;k++)
                    update(f[k][j],f[i][j]);
            }
    cout<<((f[n][d]==inf)?-1:f[n][d])<<endl;
    return 0;
}