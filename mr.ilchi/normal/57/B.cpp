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

#include <cstdio>

const int MAXS= (1<<18)+5;

int n, m, k;
int all[MAXS], cnt[MAXS];

struct range{
    int s, e;

}t[MAXS];   
/********************************/
inline void setTree (int v){
    if (t[v].s== t[v].e)
        return;
    
    int mid= ((t[v].s+t[v].e)>>1);
    int l= (v<<1), r= (v<<1)+1;

    t[l].s= t[v].s, t[l].e= mid;
    t[r].s= mid+1 , t[r].e= t[v].e;

    setTree (l); setTree (r);
}
/********************************/
inline void add (int root, int s, int e, int val){
    range &tmp= t[root];
    if (tmp.e < s || e < tmp.s)
        return;
//  cerr << tmp.s << ' ' << tmp.e << ' ' << val << endl;
    if (s <= tmp.s && tmp.e<= e){
        cnt[root]++;
        all[root]+= val+ (tmp.s-s);
        return;
    }
    int l= (root<<1), r= (root<<1)+1;
    add (l, s, e, val); add (r, s, e, val);
}
/********************************/
inline long long find (int root, int goal){
    range &tmp= t[root];
    long long r= all[root]+ ((long long)(goal-tmp.s))*cnt[root];
    if (tmp.s== tmp.e)
        return r;
    int mid= ((tmp.s+tmp.e)>>1);
    if (goal<= mid)
        return r+ find((root<<1),goal);
    return r+ find(((root<<1)+1),goal);
}
/********************************/
int main (){
    scanf ("%d%d%d", &n, &m, &k);
    
    t[1].s= 1, t[1].e= n;
    setTree (1);
    for (int i= 1;i<= m;i ++){
        int s, e, val;
        scanf ("%d%d%d", &s, &e, &val);
    //  cerr << s << ' ' << e << ' ' << val << endl;
        add (1, s, e, val);
    //  cerr << "/***************/" << endl;
    }
    long long res= 0;
    for (int i= 1;i<= k;i ++){
        int tmp;
        scanf ("%d", &tmp);
        res+= find (1, tmp);
    }
    printf ("%I64d\n", res);
    
    return 0;
}