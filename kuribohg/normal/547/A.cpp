#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
set<LL> S;
LL m,h1,a1,x1,y1,h2,a2,x2,y2;
LL b1,M1,b2,M2,X;
bool used[1000010];
void Insert(int x){used[x]=true;}
bool Count(int x){return used[x];}
void Clear(){memset(used,0,sizeof(used));}
int main()
{
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    while(h1!=a1)
    {
        Insert(h1);
        b1++,h1=(x1*h1+y1)%m;
        if(Count(h1)) {puts("-1");return 0;}
    }
    for(int i=1;i<=1000000;i++) h1=(x1*h1+y1)%m;
    Clear();
    while(true)
    {
        Insert(h1);
        M1++,h1=(x1*h1+y1)%m;
        if(Count(h1)) break;
    }
    if(!Count(a1)) M1=0;
    Clear();
    while(h2!=a2)
    {
        Insert(h2);
        b2++,h2=(x2*h2+y2)%m;
        if(Count(h2)) {puts("-1");return 0;}
    }
    for(int i=1;i<=1000000;i++) h2=(x2*h2+y2)%m;
    Clear();
    while(true)
    {
        Insert(h2);
        M2++,h2=(x2*h2+y2)%m;
        if(Count(h2)) break;
    }
    if(!Count(a2)) M2=1000000000000000000LL;
    X=b1;
    for(int i=1;i<=1000000;i++)
    {
        if(X%M2==b2%M2&&X>=b2) {printf("%I64d\n",X);return 0;}
        X=X+M1;
    }
    puts("-1");
    return 0;
}