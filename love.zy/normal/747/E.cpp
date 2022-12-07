#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
char is[1000005];
string s;
vector<string> g[500005];
int a[500005],t[500005];
string st[500005];
int i,j,k,l,m,n,ans;

int main()
{
    gets(is);n=strlen(is);l=1;s="";m=0;
    is[n]=',';k=0;
    for(i=0;i<=n;i++)
    {
        if((is[i]>='A' && is[i]<='Z') || (is[i]>='a' && is[i]<='z')){s+=is[i];continue;}
        if(is[i]>='0' && is[i]<='9'){m=m*10+is[i]-48;continue;}
        if(l<=1){l++;continue;}
        if(l>=2)
        {
            st[++k]=s;s="";
            a[k]=m;m=0;
            l=1;
        }
    }
    l=1;ans=1;t[1]=5000000;
    for(i=1;i<=k;i++)
    {
        g[l].push_back(st[i]);
        ans=max(ans,l);t[l]--;
        if(a[i]>0)t[++l]=a[i];
        while(t[l]==0)l--;
    }
    printf("%d\n",ans);
    for(i=1;i<=ans;i++)
    {
        for(j=0;j<g[i].size();j++)
        {
            if(j>0)cout<<' ';
            cout<<g[i][j];
        }
        cout<<endl;
    }
    return 0;
}