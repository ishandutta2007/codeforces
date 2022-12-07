#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
int n;
pair<int,int> A[110];
LL f[110][110][2],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&A[i].first,&A[i].second);
    sort(A+1,A+n+1);
    A[0].first=-1000000000;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=1;k++)
            {
                ans=max(ans,f[i][j][k]);
                LL pos=A[j].first+k*A[j].second;
                LL mpos=-1000000000000000000LL,nj=j,nk=k;
                for(int a=i+1;a<=n;a++)
                    for(int b=0;b<=1;b++)
                    {
                        LL npos=A[a].first+b*A[a].second;
                        if(npos>mpos) mpos=npos,nj=a,nk=b;
                        f[a][nj][nk]=max(f[a][nj][nk],f[i][j][k]+min((LL)A[a].second,npos-pos)+mpos-npos);
                    }
            }
    printf("%I64d\n",ans);
    return 0;
}