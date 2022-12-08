#include <stdio.h>

int main()
{
    int N,M,amin,amax,bmin,x,i,v;

    scanf ("%d %d",&N,&M);
    for (i=0;i<N;i++){
        scanf ("%d",&x);
        if (i == 0) amin = amax = x;
        else{
            if (amin > x) amin = x;
            if (amax < x) amax = x;
        }
    }
    for (i=0;i<M;i++){
        scanf ("%d",&x);
        if (i == 0) bmin = x;
        else{
            if (bmin > x) bmin = x;
        }
    }

    v = amin * 2 > amax ? amin * 2 : amax;
    if (v < bmin) printf ("%d",v);
    else printf ("-1");

    return 0;
}