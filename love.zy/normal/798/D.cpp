
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
 
LL a[100005],b[100005];
LL s1,s2;
LL n;
bool f[100005],y[100005];
vector<int> ans,temp;

void pri()
{
    for(unsigned int i=0;i<ans.size();i++)
    {
        if(i>0)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    exit(0);
}

struct node
{
    LL num;
    int pos;
    bool operator < (const struct node p)const
    {return num>p.num;}
};

vector<node> p;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s1+=a[i];
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]),s2+=b[i];
    for(int i=1;i<=n;i++)p.pb({a[i],i});
    p.pb({(LL)1e15,0});
    sort(p.begin(),p.end());
    ans.pb(p[1].pos);
    for(int i=3;i<p.size();i+=2)
    {
        if(b[p[i].pos]>b[p[i-1].pos])ans.pb(p[i].pos);else ans.pb(p[i-1].pos);
    }
    if(p.size()%2==1)ans.pb(p[p.size()-1].pos);
    printf("%d\n",ans.size());
    pri();
    return 0;
}