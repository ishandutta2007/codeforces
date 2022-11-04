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
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN= 500000+5;
const int maxT= (1<<20)+5;

int n;
int maxi[maxT];
int val, pos, s, e;

struct person{
    int a,b,c;
    int id;

    person (int _a=-1, int _b=-1, int _c=-1) : a(_a), b(_b), c(_c) {}

    inline void print (){
        cerr << a << ' ' << b << ' ' << c << " /// " << id << endl;
    }

}a[maxN];
/**********************************/
struct node{
    int s, e;
}t[maxT];
/**********************************/
inline bool cmpB (const person &a1, const person &a2){
    return a1.b < a2.b;
}
/**********************************/
inline bool cmpA (const person &a1, const person &a2){
    return a1.a < a2.a;
}
/**********************************/
inline void setTree (int v){
    maxi[v]= -1;
    if (t[v].s==t[v].e)
        return;
    
    int mid=(t[v].s+t[v].e)/2;
    int l= (v<<1), r=(v<<1)+1;
    
    t[l].s=t[v].s, t[l].e=mid;
    t[r].s=mid+1,  t[r].e=t[v].e;
    
    setTree (l); setTree (r);
}   
/**********************************/
inline void init (){
    t[1].s=1, t[1].e=n;
    setTree (1);
}
/**********************************/
inline int findMax (int root){
    node &tmp= t[root];
    if (tmp.e < s || e < tmp.s)
        return -1;
    if (s<= tmp.s && tmp.e<= e)
        return maxi[root];
//  return max (findMax(root*2, s, e), findMax(root*2+1, s, e));
    return max (findMax(root<<1), findMax((root<<1)+1));
}   
/**********************************/
inline void add (int root){
    node &tmp = t[root];
    maxi[root]= max (maxi[root], val);
    if (tmp.s==tmp.e)
        return;
    
    int mid= (tmp.s+tmp.e)/2;

    if (pos<= mid)
        add (root<<1);
    else
        add ((root<<1)+1);
}
/**********************************/
int main (){
    scanf ("%d", &n);
    for (int i=1;i<= n;i ++)
        scanf ("%d", &a[i].a);
    for (int i=1;i<= n;i ++)
        scanf ("%d", &a[i].b);
    for (int i=1;i<= n;i ++)
        scanf ("%d", &a[i].c);
    
    sort (a+1, a+n+1, cmpB);
    for (int i=1, cur=1;i<= n;i ++, cur++){
        int j=i;
        while (j<=n && a[i].b==a[j].b)
            a[j++].id= cur;
        i=j-1;
    }
    init ();
    sort (a+1, a+n+1, cmpA);
    int res= 0;
    for (int i= n;i> 0;i --){
        int j=i;
        while (j>0 && a[j].a==a[i].a){
            s= a[j].id+1, e= n;
            if (a[j].c < findMax (1))
                res ++;
            j --;
        }
        for (int z=j+1;z<=i;z ++){
            pos= a[z].id, val=a[z].c;
            add (1);
        }
        i= j+1;
    }
    printf ("%d\n", res);

    return 0;
}