#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <int> v[150003];
vector <int> cs[150003];
int heap[150003],elemx,val[150003];
bool viz[150003];
int baga (int ch, int pr)
{
    heap[++elemx]=pr;
    val[elemx]=ch;
    int poz=elemx;
    while(poz>1)
    {
        if(heap[poz]<heap[poz/2])
        {
            swap(heap[poz],heap[poz/2]);
            swap(val[poz],val[poz/2]);
            poz>>=1;
        }
        else
            break;
    }
}
int scoate ()
{
    swap(heap[1],heap[elemx]);
    swap(val[1],val[elemx]);
    --elemx;
    int poz=1;
    while(poz*2+1<=elemx)
    {
        if(heap[poz]>min(heap[poz*2],heap[poz*2+1]))
        {
            if(heap[poz*2]<heap[poz*2+1])
            {
                swap(heap[poz],heap[poz*2]);
                swap(val[poz],val[poz*2]);
                poz<<=1;
            }
            else
            {
                swap(heap[poz],heap[poz*2+1]);
                swap(val[poz],val[poz*2+1]);
                poz<<=1;
                ++poz;
            }
        }
        else
            break;
    }
    if(poz*2==elemx && heap[elemx]<heap[poz])
    {
        swap(heap[poz],heap[elemx]);
        swap(val[poz],val[elemx]);
    }
}
int main()
{
    long long s=0,i=0,j=0,n,m,d,s1=0,ra,rb,rc,rd,ok;
    char c;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        cs[a].push_back(i);
        cs[b].push_back(i);
    }
    int nc=1;
    for(j=1;j<=n;++j)
    {
        viz[nc]=true;
        for(i=0;i<v[nc].size();++i)
        {
            int nn=v[nc][i];
            if(viz[nn])
                continue;
            baga(nn,cs[nc][i]);
        }
        cout<<nc<<' ';
        nc=val[1];
        scoate();
    }
    return 0;
}