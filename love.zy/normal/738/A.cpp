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
  
string s,ans;
string ss[51];
int i,j,k,n;

int main()
{
    ans="";ss[1]="ogo";
    for(i=2;i<=50;i++)ss[i]=ss[i-1]+"go";
    cin>>n>>s;
    i=0;
    while(i<n)
    {
        string t;
        bool f=false;
        for(k=50;k>=1;k--)
        {
            string t="";j=i;
            while(j<i+2*k+1 && j<n)t+=s[j],j++;
            if(t==ss[k]){ans+="***";i=j;f=true;break;}
        }
        if(f)continue;
        ans+=s[i];i++;
    }
    cout<<ans;
    return 0;
}