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
 *
 */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int maxN= 100000+5;

int n, m, len;
int Pow[maxN], next[maxN], dp[maxN];

inline void init(){
    for (int i=1;i<= n;i+= len){
        int end= min(i+len-1, n);
        for (int j=end;j>= i;j --){
            int tmp= j + Pow[j];
            if (tmp > end)
                dp[j]=1, next[j]= j;
            else
                dp[j]= dp[tmp]+1, next[j]= next[tmp];
        }
    }
}
/**********************************/
inline void change(int pos, int val){
    Pow[pos]= val;
    
    int start= (pos/len)*len + 1;
    int end= min (start+len-1, n);
    
    for (int i=pos;i>=start;i --){
        int tmp= i + Pow[i];
        if (tmp > end){
            dp[i]=1, next[i]= i;
        }       
        else
            dp[i]= dp[tmp]+1, next[i]= next[tmp];
    }
}
/**********************************/
inline void check (int v){
    int res= 0, past=v;
    while (v<= n){
        res+= dp[v];
        past= next[v];
        v= next[v] + Pow[next[v]];
    }
    printf ("%d %d\n", past, res);
}
/**********************************/
int main(){
    scanf ("%d%d", &n, &m);
    len= (int)(sqrt((double)n));
    for (int i=1;i<= n;i ++)
        scanf ("%d", Pow+i);
    
    init ();
    for (int i=1;i<= m;i ++){
        char ord;
        scanf (" %c", &ord);
        if (ord == '0'){
            int a,b;
            scanf ("%d%d", &a, &b);
            change (a,b);
        }
        else{
            int a;
            scanf ("%d", &a);
            check (a);
        }
    }

    return 0;
}