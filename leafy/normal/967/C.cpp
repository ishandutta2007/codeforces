#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100005
int n,m,cl,ce,v;
int l[N],e[N];
int q;
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
    for(int i=0;i<cl;i++) scanf("%d",&l[i]);
    for(int i=0;i<ce;i++) scanf("%d",&e[i]);
    scanf("%d",&q);
    int xa,xb,ya,yb,ans;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        ans=(1<<30);
        if(ya>yb) swap(xa,xb),swap(ya,yb);
        if(xa==xb){printf("%d\n",yb-ya);continue;}
        int * t1=lower_bound(l,l+cl,ya);
        if(*t1!=0)
        {
            if((*t1)<=yb) ans=min(ans,abs(xb-xa)+yb-ya);
            else ans=min(ans,abs(xb-xa)+(*t1)-ya+(*t1)-yb);
            
        }
        --t1;
        if(*t1!=0) ans=min(ans,abs(xb-xa)+ya+yb-2*(*t1));
        int * t2=lower_bound(e,e+ce,ya);
        if(*t2!=0)
        {
            if((*t2)<=yb) ans=min(ans,(int)ceil(double(abs(xb-xa))/v)+yb-ya);
            else ans=min(ans,(int)ceil(double(abs(xb-xa))/v)+(*t2)-ya+(*t2)-yb);
        }
        --t2;
        if(*t2!=0) ans=min(ans,(int)ceil(double(abs(xb-xa))/v)+ya+yb-2*(*t2));
        printf("%d\n",ans);
    }
    //int *it =lower_bound(l,l+cl,0);--it;
    //cout<<(*it);
    return 0;
}