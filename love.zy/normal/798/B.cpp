
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
  
string s[51],t;
int n;

int main()
{
    cin>>n;
    if(n==1){printf("0");return 0;}
    for(int i=1;i<=n;i++)cin>>s[i];
    int l=s[1].length();
    int ans=1e9;
    for(int p=0;p<l;p++)
    {
        int sum=p;
        for(int i=2;i<=n;i++)
        {
            t=s[i];
            while(t!=s[1])
            {
                sum++;
                if(sum>l*i){printf("-1");return 0;}
                char c=t[0];
                for(int j=0;j<l-1;j++)t[j]=t[j+1];
                t[l-1]=c;
            }
        }
        ans=min(ans,sum);
        char c=s[1][0];
        for(int j=0;j<l-1;j++)s[1][j]=s[1][j+1];
        s[1][l-1]=c;
    }
    printf("%d\n",ans);
    return 0;
}