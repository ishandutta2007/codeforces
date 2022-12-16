//#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//#include<map>
#include<math.h>
//#include<time.h>
//#include<complex>
#include<algorithm>
using namespace std;
 
int n;
#define maxn 10011
char s[maxn],t[maxn];int cnts[30],cntt[30],ans[maxn],lans=0;

char tmp[maxn];
void shift(int x)
{
    if (x==0) {lans--; return;}
    memcpy(tmp,s,sizeof(char)*(n+3));
    int cnt=0; x=n-x+1;
    for (int i=n;i>=x;i--) s[++cnt]=tmp[i];
    for (int i=1;i<x;i++) s[++cnt]=tmp[i];
}

int findpos(int p,int rr)
{
    for (int i=rr;i;i--)
        if (s[i]==t[p]) return i;
    return maxn*2;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1); scanf("%s",t+1);
    for (int i=1;i<=n;i++) cnts[s[i]-'a']++,cntt[t[i]-'a']++;
    for (int i=0;i<26;i++) if (cnts[i]!=cntt[i]) {puts("-1"); return 0;}
    
    int p1=(1+n)>>1,p2=p1;
    int p=findpos(p1,n); p1--; p2++;
    if (p!=n) {ans[++lans]=n-p; shift(n-p);}
    bool rev=0;
    for (int now=1,p;p1;p1--,p2++,now+=2,rev^=1)
    {
        if (rev==0) p=findpos(p1,n-now); else p=findpos(p2,n-now);
        shift(ans[++lans]=n-p);
        shift(ans[++lans]=n);
        shift(ans[++lans]=now);
        if (rev==0) p=findpos(p2,n); else p=findpos(p1,n);
        shift(ans[++lans]=n-p+1);
        shift(ans[++lans]=p-now-2);
    }
    if (n&1) {if (rev) shift(ans[++lans]=n);}
    else
    {
        if (rev) shift(ans[++lans]=n-1);
        else
        {
            shift(ans[++lans]=n-1);
            shift(ans[++lans]=1);
            shift(ans[++lans]=n);
        }
    }
    
    printf("%d\n",lans);
    for (int i=1;i<=lans;i++) printf("%d ",ans[i]);
    return 0;
}