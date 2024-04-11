#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
#include<functional>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

ll dp[55][7];
ll K,x,n,m;

char ch1[110],ch2[110];

void output(int x,int y)
{
    int a=1,b=1;
    if(ch1[0]=='A')a=0;
    if(ch2[0]=='A')b=0;
    while(x--)ch1[a]='A',ch1[a+1]='C',a+=2;
    while(y--)ch2[b]='A',ch2[b+1]='C',b+=2;
    for(a=max(a,1);a<n-1;a++)ch1[a]='X';
    for(b=max(b,1);b<m-1;b++)ch2[b]='X';
    printf("%s\n%s",ch1,ch2);
}

int main()
{
    scanf("%lld%lld%lld%lld",&K,&x,&n,&m);
    int i;
    dp[1][3]=1,dp[2][4]=1;
    dp[1][5]=dp[1][6]=1,dp[2][5]=dp[2][6]=2;
    for(i=3;i<=K;i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0]+(dp[i-1][6]==1?1:0);
        dp[i][2]=dp[i-1][2]+dp[i-2][2]+(dp[i-1][6]==2?1:0);
        dp[i][3]=dp[i-1][3]+dp[i-2][3];
        dp[i][4]=dp[i-1][4]+dp[i-2][4];
        dp[i][6]=dp[i-2][6];
        if(i==3)dp[3][2]--;
    }
    bool flag=0;
    for(i=0;i<81;i++){
        if(i==36){
            i++;
            i--;
        }
        int pn=n-2,pm=m-2;
        int tmp=i;
        if(tmp%3==0)ch1[0]='A',pn++;
        else if(tmp%3==1)ch1[0]='C';
        else ch1[0]='X';
        tmp/=3;
        if(tmp%3==0)ch1[n-1]='A';
        else if(tmp%3==1)ch1[n-1]='C',pn++;
        else ch1[n-1]='X';
        tmp/=3;
        if(tmp%3==0)ch2[0]='A',pm++;
        else if(tmp%3==1)ch2[0]='C';
        else ch2[0]='X';
        tmp/=3;
        if(tmp%3==0)ch2[m-1]='A';
        else if(tmp%3==1)ch2[m-1]='C',pm++;
        else ch2[m-1]='X';
        ll a=dp[K][3],b=dp[K][4],c=dp[K][2],d=dp[K][0];
        int j,k;
        for(j=0;j<=pn/2;j++){
            if(j==0&&pn==2&&ch1[0]=='A'&&ch1[n-1]=='C')j++;
            for(k=0;k<=pm/2;k++){
                if(k==0&&pm==2&&ch2[0]=='A'&&ch2[m-1]=='C')k++;
                ll ans=0;
                ans=a*j+b*k;
                if(ch2[m-1]=='A'&&ch1[0]=='C')ans+=d;
                if(ch2[m-1]=='A'&&ch2[0]=='C')ans+=c;
                if(ch1[n-1]=='A'&&ch2[0]=='C')ans+=a;
                if(ans==x){
                    output(j,k);
                    flag=1;
                    return 0;
                }
            }
        }
    }
    if(!flag)printf("Happy new year!");
    return 0;
}