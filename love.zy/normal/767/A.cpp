
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
#define scan2(x, y) scanf("%d%d", &x, &y)
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
 
int n;
bool a[100005];

int main()
{
    scanf("%d",&n);
    int x=n;
    for(int p=1;p<=n;p++)
    {
        int t;
        scanf("%d",&t);
        a[t]=true;
        if(t!=x){printf("\n");continue;}
        int o=0;
        while(a[x])
        {
            o++;
            if(o>1)printf(" ");
            printf("%d",x);
            x--;
        }
        printf("\n");
    }
    return 0;
}