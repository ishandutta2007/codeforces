/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-09-18
File: G.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;


int k;
int a[18];
int main()
{
    int _;
    for (scanf("%d",&_);_;_--)
    {
        scanf("%d",&k);
        int sum=0,ans=1000000000,t,kk;
        for (int i=1;i<=7;++i)
        {
            scanf("%d",a+i),a[i+7]=a[i];
            if (a[i]==1) ++sum;
        }   
        for (int l,r,i=1;i<=7;++i)
        {
            l=i;r=i+6;
            {
                if (k%sum==0) kk=sum,t=k/sum-1;
                else kk=k%sum,t=k/sum;
                for (int j=l;j<=r;++j)
                {
                    kk-=a[j];
                    if (kk==0) {ans=min(ans,t*7+j-l+1);break;}
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}