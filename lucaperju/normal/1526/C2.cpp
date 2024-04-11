#include <bits/stdc++.h>
using namespace std;
struct heap
{
    int val;
    heap*son;
    heap*nxt;
};
heap* emptyheap=new heap
{
    0,NULL,NULL
};
heap* meld (heap* a, heap* b)
{
    if(a==emptyheap)
        return b;
    if(b==emptyheap)
        return a;
    if(a->val>b->val)
    {
        b->nxt=a->son;
        a->son=b;
        return a;
    }
    else
    {
        a->nxt=b->son;
        b->son=a;
        return b;
    }
}
int getmax (heap* a)
{
    return a->val;
}
heap* insert (heap* a, int val)
{
    heap* b=new heap
    {
        val,emptyheap,emptyheap
    };
    return meld(a,b);
}
heap* twopass (heap* a)
{
    if(a==emptyheap)
        return emptyheap;
    if(a->nxt==emptyheap)
        return a;
    return meld(meld(a,a->nxt),twopass(a->nxt->nxt));
}
heap* del (heap* a)
{
    return twopass(a->son);
}
heap* myHeap = emptyheap;
long long v[200003];
long long sp[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        sp[i]=v[i]+sp[i-1];
    long long s=0;
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]<0)
            myHeap=insert(myHeap,-v[i]);
        while(s+sp[i]<0)
        {
            s+=getmax(myHeap);
            myHeap=del(myHeap);
            ++cnt;
        }
    }
    cout<<n-cnt;
	return 0;
}