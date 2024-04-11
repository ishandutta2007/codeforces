/*****************************
Author : lizi
Email  : zyli@smail.nju.edu.cn
*****************************/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
LL k,x,sum,ans=0;

int main()
{
    scanf("%d%lld",&n,&k);sum=0;
    for(int i=1;i<=n;i++)
    {
        bool f=false;
        if(sum==0)f=true;
        scanf("%lld",&x);
        sum+=x;
        if(sum>=k)
        {
            ans+=sum/k;
            sum%=k;
        }else
        {
            if(!f)
            {
                ans++;
                sum=0;
            }
        }

        //ans+=s;a[i]-=s*k;
    }
    //LL lack=k;
    if(sum>0)ans++;
    printf("%lld\n",ans);
    return 0;
}