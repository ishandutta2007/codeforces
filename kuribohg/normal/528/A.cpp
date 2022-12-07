#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<iterator>
typedef long long LL;
using namespace std;
int n,m,k,x;
LL ans;
multiset<int> Sx,Sy;
multiset<int> dx,dy;
multiset<int>::iterator it1,it2;
char op[10];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    Sx.insert(0),Sx.insert(n);
    Sy.insert(0),Sy.insert(m);
    dx.insert(n);
    dy.insert(m);
    while(k--)
    {
        scanf("%s%d",op,&x);
        if(op[0]=='H')
        {
            it1=Sy.upper_bound(x);
            it2=it1,it2--;
            dy.erase(dy.find((*it1)-(*it2)));
            dy.insert((*it1)-x);
            dy.insert(x-(*it2));
            Sy.insert(x);
            ans=(LL)(*dx.rbegin())*(LL)(*dy.rbegin());
            printf("%I64d\n",ans);
        }
        else
        {
            it1=Sx.upper_bound(x);
            it2=it1,it2--;
            dx.erase(dx.find((*it1)-(*it2)));
            dx.insert((*it1)-x);
            dx.insert(x-(*it2));
            Sx.insert(x);
            ans=(LL)(*dx.rbegin())*(LL)(*dy.rbegin());
            printf("%I64d\n",ans);
        }
    }
    return 0;
}