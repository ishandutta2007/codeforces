
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

char s[20];
int l;

int main()
{
    scanf("%s",s+1);
    l=strlen(s+1);
    int ans=0;
    for(int i=1;i<=(l+1)>>1;i++)
        if(s[i]!=s[l+1-i])ans++;
    if(ans==1 || (ans==0 && l&1))printf("YES\n");else printf("NO\n");
    return 0;
}