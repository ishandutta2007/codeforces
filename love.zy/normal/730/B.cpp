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

int QA(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    char c='0';
    while(c!='>' && c!='=' && c!='<')c=getchar();
    if(c=='>')return 1;
    if(c=='=')return 0;
    if(c=='<')return -1;
    return 1000;
}

int i,j,k,l,m,n,T;

int ma[5000];
int mi[5000];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        i=j=0;
        for(k=1;k+1<=n;k+=2)
        {
            m=QA(k,k+1);
            if(m>=0){ma[++j]=k;mi[j]=k+1;}else {ma[++j]=k+1;mi[j]=k;}
        }
        if(k==n){ma[++j]=n;mi[j]=n;}
        while(j-i>1)
        {
            k=i+1;l=i=j;
            while(k+1<=l)
            {
                m=QA(ma[k],ma[k+1]);
                if(m>=0)ma[++j]=ma[k];else ma[++j]=ma[k+1];
                m=QA(mi[k],mi[k+1]);
                if(m<0)mi[j]=mi[k];else mi[j]=mi[k+1];
                k+=2;
            }
            if(k==l){ma[++j]=ma[l];mi[j]=mi[l];}
        }
        printf("! %d %d\n",mi[j],ma[j]);
        fflush(stdout);
    }
    return 0;
}