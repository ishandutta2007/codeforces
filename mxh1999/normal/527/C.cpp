#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
set<int>    W,H;
map<int,int>    nW,nH;
int w,h,n;

int main()
{
    scanf("%d%d%d",&w,&h,&n);
    nW[w]=1;nH[h]=1;
    W.insert(0),W.insert(w);
    H.insert(0),H.insert(h);
    for (int i=1;i<=n;i++)
    {
        int x;
        char ch=getchar();
        while (ch!='V' && ch!='H')  ch=getchar();
        scanf("%d",&x);
        if (ch=='V')
        {
            set<int>::iterator it=W.lower_bound(x),it2=it;
            if (*it==x) continue;
            it--;
            nW[(*it2)-(*it)]--;
            if (nW[(*it2)-(*it)]==0)    nW.erase((*it2)-(*it));
            nW[x-(*it)]++;nW[(*it2)-x]++;
            W.insert(x);
        }   else
        {
            set<int>::iterator it=H.lower_bound(x),it2=it;
            if (*it==x) continue;
            it--;
            nH[(*it2)-(*it)]--;
            if (nH[(*it2)-(*it)]==0)    nH.erase((*it2)-(*it));
            nH[x-(*it)]++;nH[(*it2)-x]++;
            H.insert(x);
        }
        map<int,int>::reverse_iterator it=nW.rbegin(),it2=nH.rbegin();
        int v1=it->first,v2=it2->first;
        ll ans=v1;
        ans*=v2;
        printf("%I64d\n",ans);
    }
}