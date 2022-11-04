/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN= 1000*100+5;

bool mark[MAXN];
int n, k, res;
int a[MAXN];
int qmin[MAXN], qmax[MAXN];

inline int check (int v){
    memset (mark, false, sizeof mark);

    int hmin= 1, tmin= 1, hmax= 1, tmax= 1;
    for (int i= 1;i< v;i ++){
        while (hmin < tmin && a[qmin[tmin-1]]>= a[i])
            tmin --;
        qmin[tmin ++]= i;
        
        while (hmax < tmax && a[qmax[tmax-1]]<= a[i])
            tmax --;
        qmax[tmax ++]= i;
    }   
    int r= 0;
    for (int i= v;i<= n;i ++){
        while (hmin < tmin && a[qmin[tmin-1]]>= a[i])
            tmin --;
        qmin[tmin ++]= i;
        
        while (hmax < tmax && a[qmax[tmax-1]]<= a[i])
            tmax --;
        qmax[tmax ++]= i;

        int diff= a[qmax[hmax]]- a[qmin[hmin]];
        if (diff<= k){
            r ++;
            mark[i]= true;
        }
        if (i-qmax[hmax]== (v-1))
            hmax ++;
        if (i-qmin[hmin]== (v-1))
            hmin ++;
    }
    return r;
}
/******************************************/
inline void bs (){
    int s= 1, e= n;
    while (s<= e){
        int mid= ((s+e)>>1);
        if (check (mid)){
            s= mid+1;
            res= mid;
        }
        else
            e= mid-1;
    }
}   
/*****************************************/
int main (){
    scanf ("%d%d", &n, &k);
    for (int i= 1;i<= n;i ++)
        scanf ("%d", &a[i]);

    bs (); 

    printf ("%d %d\n", res, check (res));
    for (int i= 1;i<= n;i ++)
        if (mark[i])
            printf ("%d %d\n", i-res+1, i);

    return 0;
}