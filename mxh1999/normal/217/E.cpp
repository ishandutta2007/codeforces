//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxlen 3100000
#define maxn 50010
struct Str
{
    int l;
    char *s;
}   str[maxn<<2];
int tot;
char s[maxlen];
int k;
int n,l[maxn],r[maxn];
char ans[maxlen];

int cut(int pos)
{
    for (int i=0;i<tot;i++)
    if (pos==0)
    {
        tot++;
        for (int k=tot-1;k>i;k--)   str[k]=str[k-1];
        return i;
    }   else
    if (str[i].l<=pos)  pos-=str[i].l;  else
    {
        tot+=2;
        for (int k=tot-1;k>i+1;k--) str[k]=str[k-2];
        str[i+2].l=str[i].l-pos;
        str[i+2].s=str[i].s+pos;
        str[i].l=pos;
        return i+1;
    }
    return tot++;
}
void getans(int h,int t)
{
    int l=0;
    for (int i=0;t>=0 && i<tot;i++)
    if (str[i].l<=h)
    {
        h-=str[i].l;
        t-=str[i].l;
    }   else
    {
        for (int k=max(0,h);k<str[i].l && k<=t;k++) ans[l++]=str[i].s[k];
        int tmp=min(str[i].l,t);
        h-=tmp;
        t-=tmp;
    }
}
void deal(int d,int len)
{
    if (d<0)
    {
        Str tmp;
        tmp.l=len;
        tmp.s=s+1;
        str[tot++]=tmp;
        return;
    }
    if (r[d]>=len)
    {
        deal(d-1,len);
        return;
    }
    int c=r[d]-l[d]+1;
    if (r[d]+c>=len)
    {
        deal(d-1,r[d]);
        Str tmp;
        tmp.l=len-r[d];
        tmp.s=new char[len-r[d]];
        int c_2=c/2;
        int D=(tmp.l>=c_2)?c:(tmp.l*2);
        getans(l[d],l[d]+D-1);
        for (int i=0;i<tmp.l;i++)
        if (i<c_2)  tmp.s[i]=ans[i*2+1];else    tmp.s[i]=ans[(i-c_2)<<1];
        str[tot++]=tmp;
    }   else
    {
        deal(d-1,len-c);
        int pos=cut(r[d]+1);
        Str tmp;
        tmp.l=c;
        tmp.s=new char[c];
        int c_2=c/2;
        getans(l[d],r[d]);
        for (int i=0;i<c;i++)
        if (i<c_2)  tmp.s[i]=ans[i*2+1];else tmp.s[i]=ans[(i-c_2)<<1];
        str[pos]=tmp;
    }
}

int main()
{
    scanf("%s",s+1);
    scanf("%d",&k);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d%d",&l[i],&r[i]);
    tot=1;
    str[0].l=1;
    str[0].s=new char[1];
    str[0].s[0]=' ';
    deal(n-1,k);
    getans(0,k);
    ans[k+1]=0;
    printf("%s\n",ans+1);
    return 0;
}