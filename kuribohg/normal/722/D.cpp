#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],ans;
multiset<int> S;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans=max(ans,a[i]);
    if(n==1) {puts("1");return 0;}
    for(int i=1;i<=n;i++) S.insert(a[i]);
    while(true)
    {
        multiset<int>::iterator it=S.end();
        --it;
        int x=(*it)>>1,tmp=(*it);
        S.erase(it);
        while(S.find(x)!=S.end()) x>>=1;
        if(x==0)
        {
            for(multiset<int>::iterator it=S.begin();it!=S.end();++it)
                printf("%d ",(*it));
            printf("%d\n",tmp);
            break;
        }
        multiset<int>::iterator it2=S.end();
        it2--;
        ans=min(ans,max(*it2,x));
        S.insert(x);
    }
    return 0;
}