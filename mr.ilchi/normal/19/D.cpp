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
#include <cstdio>
#include <vector>
#include <map>
#include <set>

#define Pair pair<int,int> 

using namespace std;

const int maxN= 200000+5;
const int maxT= (1<<19)+5;

char type[maxN];
int n;
int next[maxN], maxi[maxT];
Pair par[maxN], f[maxN];
set < Pair > sit;
map < Pair, int> code;

struct node{
    int s,e;
}t[maxT];
/******************************************/
inline int Find (int root, int pos, int cost){
    if (t[root].e< pos)
        return -1;

    if (t[root].s == t[root].e)
        return (cost < maxi[root]) ? t[root].s : -1;

    int mid= (t[root].s + t[root].e)/2, lef= (root<<1), rig= (root<<1)+1;
    if (cost < maxi[lef] && pos<= mid){
        int ret= Find (lef, pos, cost);
        if (ret!=-1)
            return ret;
    }
    if (cost < maxi[rig])
        return Find (rig, pos, cost);
    return -1;
}
/************************************************/
inline void add (int root, int pos, int cost){
    if (t[root].s == t[root].e){
        maxi[root]= cost;
        return;
    }
    int mid= (t[root].s + t[root].e)/2, lef= (root<<1), rig= (root<<1)+1;
    
    if (pos<= mid)
        add (lef, pos, cost);
    else
        add (rig, pos, cost);

    maxi[root]= max (maxi[lef], maxi[rig]);
}
/***********************************************/
inline void settree (int root){
    if (t[root].s == t[root].e)
        return;
    
    int mid= (t[root].s + t[root].e)/2, lef= (root<<1), rig= (root<<1)+1;
    
    t[lef].s= t[root].s, t[lef].e= mid;
    t[rig].s= mid+1, t[rig].e= t[root].e;

    settree (lef); settree (rig);
}
/***********************************************/
int main(){
    scanf ("%d", &n);
    char ord[10];
    for (int i=1;i<= n;i ++){
        int x, y;
        scanf (" %s%d%d", ord, &x, &y);
        type[i]= ord[0];
        f[i]= make_pair (x,y);
        sit.insert (f[i]);
    }
    int cur=0;
    for (set <Pair> :: iterator i= sit.begin();i!= sit.end();){
        set <Pair> :: iterator j=i;
        int tmp= cur+1;
        while (j!=sit.end() && (j->first)==(i->first)){
            code[*j]= ++cur;
            par [cur]= *j;
            j ++;
        }
        while (tmp<=cur){
            next[tmp++]= cur+1;
        }
        i=j;
    }
    t[1].s= 1, t[1].e= sit.size();
    settree (1);
    for (int i=1;i<= n;i ++){
        int id= code[f[i]];
        if (type[i]== 'a'){
            add (1, id, f[i].second);
        }
        else if (type[i]== 'r'){
            add (1, id, 0);
        }
        else{
            int low= Find (1, next[id], f[i].second);
            if (low==-1)
                puts("-1");
            else
                printf ("%d %d\n", par[low].first, par[low].second);
        }
    }

    return 0;
}