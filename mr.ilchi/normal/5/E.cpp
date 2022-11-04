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
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN= 1000*1000+5;

int n;
int a[MAXN], Left[MAXN], lmax[MAXN];
long long res;

inline void solve (int s, int e){
    if (e-s< 2)
        return;

    int mid= ((s+e)>>1);

    solve (s, mid);
    solve (mid+1, e);

    int cur_max= 0, lsize= 0;
    for (int i= mid-1;i>= s;i --){
        if (cur_max<= min (a[i], a[mid]))
            res ++;
        if (max (cur_max, a[mid])<= a[i]){
            Left[lsize]= a[i];
            lmax[lsize++]= cur_max;
        }
        cur_max= max (cur_max, a[i]);
    }
    cur_max= 0;
    int p1= 0, p2= 0;
    for (int i= mid+1;i< e;i ++){
        if (cur_max<= min (a[i], a[mid]))
            res ++;
        if (max (cur_max, a[mid])<= a[i]){
    //      int p1= upper_bound (lmax, lmax+lsize, a[i])- lmax;
    //      int p2= lower_bound (Left, Left+lsize, cur_max)- Left; 
            while (p1< lsize && lmax[p1]<= a[i])
                p1 ++;
            while (p2< lsize && Left[p2]< cur_max)
                p2 ++;
            res+= max (0, p1-p2);
        }
        cur_max= max (cur_max, a[i]);
    }
}
/***************************************/
int main (){
    for (int i= 1;i<= 10;i ++)
        lmax[i]= i;
    scanf ("%d", &n);
    int pmax= 1;
    for (int i= 1;i<= n;i ++){
        scanf ("%d", &a[i]);
        if (a[pmax] < a[i])
            pmax= i;
    }
    reverse (a+1, a+pmax);
    reverse (a+pmax, a+n+1);

    solve (1, n);
    lmax[n-1]= 0;
    for (int i= n-1;i> 0;i --) 
        lmax[i-1]= max (lmax[i], a[i]);
    
    int cur_max= 0;
    for (int i= 1;i< n;i ++){
        if (cur_max<= a[i])
            res ++;
        else if (lmax[i]<= a[i])
            res ++;

        cur_max= max (cur_max, a[i]);
    }
    cout << res << endl;

    return 0;
}