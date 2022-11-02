#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

int n,m,k,x,a;
int sum=0;
set<int> S;
set<int>::iterator it,it2;

int query(int t)
{
    t++;
    return t/(a+1);
}
int main()
{
    read(n),read(k),read(a);
    S.insert(0);
    S.insert(n+1);
    sum=query(n);
    if (sum<k)  {printf("0\n");return 0;}
    read(m);
    for (int i=1;i<=m;i++)
    {
        read(x);
        it=S.lower_bound(x);
        if (*it==x) continue;
        it2=it;
        it--;
        int q=(*it2)-(*it)-1,q1=x-(*it)-1,q2=(*it2)-x-1;
        sum-=query(q);
        sum+=query(q1)+query(q2);
        if (sum<k)  {printf("%d\n",i);return 0;}
        S.insert(x);
    }
    printf("-1\n");
    return 0;
}