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
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxN= 100+5;

bool no;
bool mark[maxN], flag[maxN];
int n,e;
int val[maxN];

struct edge{
    int v,gcd,lcm;
    ll multi;

    edge (int _v=-1, int _gcd=-1, int _lcm=-1, ll _multi=-1) : v(_v), gcd(_gcd), lcm(_lcm), multi(_multi) {}
};
vector <edge> adj[maxN];
/***************************************/
inline int gcd (int a1, int a2){
    return a1 ? gcd(a2%a1,a1) : a2;
}
/***************************************/
inline void dfs (int v){
    flag[v]= true;
    for (int i=0;i< (int)adj[v].size() && !no;i ++){
        edge &tmp= adj[v][i];
        if (!flag[tmp.v]){
            ll k= tmp.multi/val[v];
            if (k==0 || (tmp.lcm)%k!=0){
                no=true; 
                return;
            }
            val[tmp.v]= (int)k;
            dfs (tmp.v);
        }
        if (!(gcd(val[v],val[tmp.v])==tmp.gcd && (ll)val[v]*val[tmp.v]==tmp.multi)){
            no= true;
            return;
        }   
    }
}
/***************************************/
inline void setMark (int v){
    mark[v]=true;
    for (int i=0;i< (int)adj[v].size();i ++){
        int tmp= adj[v][i].v;
        if (!mark[tmp])
            dfs (tmp);
    }
}
/***************************************/
inline void setVal(){
    for (int i=1;i<=n;i ++)
        val[i]=1;
    for (int i=1;i<=n;i ++){
        if (!mark[i]){
            if (adj[i].size()==0){
                val[i]=1; mark[i]=true;
                continue;
            }
            int k= adj[i][0].lcm;
            int len= (int)sqrt(double(k));
            bool cor= false;
            for (int j=1;j<=len;j ++){
                if (k%j==0){
                    memset (flag, false, sizeof flag);
                    val[i]=j; no=false; 
                    dfs (i);
                    if (no==false){
                        cor= true;
                        break;
                    }
                    memset (flag, false, sizeof flag);
                    
                    val[i]= k/j; no=false;
                    dfs (i);
                    
                    if (no==false){
                        cor= true;
                        break;
                    }
                }   
            }
            if (!cor){
                printf ("NO\n");
                return;
            }
            setMark(i);
        }
    }
    printf ("YES\n");
    for (int i=1;i<=n;i ++)
        printf ("%d ", val[i]);
    printf ("\n");
}
/***************************************/
int main(){
    scanf ("%d%d", &n, &e);
    for (int i=1;i<=e;i++){
        int x,y,Gcd,Lcm;
        scanf ("%d%d%d%d", &x, &y, &Gcd, &Lcm);
        if (Lcm%Gcd!=0){
            printf ("NO\n");
            return 0;
        }
        adj[x].push_back (edge(y,Gcd,Lcm,(ll)Gcd*Lcm));
        adj[y].push_back (edge(x,Gcd,Lcm,(ll)Gcd*Lcm));
    }
    setVal();
    return 0;
}