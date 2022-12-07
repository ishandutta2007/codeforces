#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<iterator>
using namespace std;
typedef long long LL;
set<pair<LL,LL> > ans;
LL S;
int main()
{
    scanf("%I64d",&S);
    LL a=1;
    while(true)
    {
        LL x=a*(a+1)*(2*a+1)/6;
        LL s=S;
        s-=x;
        if(s<0) break;
        LL p=a*(a+1)/2;
        LL b;
        b=a+s/p;
        if(s%p==0&&b>=a) ans.insert(make_pair(a,b)),ans.insert(make_pair(b,a));
        a++;
    }
    printf("%d\n",(int)ans.size());
    for(set<pair<LL,LL> >::iterator it=ans.begin();it!=ans.end();++it)
        printf("%I64d %I64d\n",it->first,it->second);
    return 0;
}