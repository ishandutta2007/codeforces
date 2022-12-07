
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
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

string s[1005];
int n,sum,ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=0;i<7;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
            sum+=s[j][i]-48;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}