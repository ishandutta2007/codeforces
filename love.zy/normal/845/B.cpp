
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

string s;
int n,m;

int main()
{
    cin>>s;
    int ans=9;
    for(int n=0;n<=27;n++)
    {
        int p1=9,p2=9;
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                for(int k=0;k<=9;k++)
                    if(i+j+k==n)
                    {
                        int cnt=0;
                        if(i!=s[0]-48)cnt++;
                        if(j!=s[1]-48)cnt++;
                        if(k!=s[2]-48)cnt++;
                        p1=min(cnt,p1);
                    }
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                for(int k=0;k<=9;k++)
                    if(i+j+k==n)
                    {
                        int cnt=0;
                        if(i!=s[3]-48)cnt++;
                        if(j!=s[4]-48)cnt++;
                        if(k!=s[5]-48)cnt++;
                        p2=min(cnt,p2);
                    }
        ans=min(ans,p1+p2);
    }
    printf("%d\n",ans);
    return 0;
}