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
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxN= 200000+5;

int Q,n;
int a[maxN], o[maxN];

inline void print (int s, int e){
    while (s<=e)
        printf ("%d ", s++);
}
/**************************************/
inline void findSet(){
    puts ("YES");
    if (n==1){
        puts("1");
        return;
    }

    int N=2*n;
    ll sumA=0, sumO=0;
    for (int i=1;i<N;i ++)
        sumA+= a[i], sumO+= o[i];

    sumA= (sumA+1)/2; sumO= (sumO+1)/2;
    ll curA=0, curO=0;
    for (int i=1;i<n;i ++)
        curA+= a[i], curO+= o[i];

    bool flagA= (sumA<=curA), flagO= (sumO<=curO);
    for (int i=n;i<=N;i ++){
        if (curA<sumA && curO<sumO){
            print (1,i-n); print (i,N-1);
            printf ("\n");
            return;
        }

        if (i==N)
            break;
        
        curA+= a[i] - a[i-n+1]; curO+= o[i] - o[i-n+1];

        if ((sumA<=curA || flagA) && (sumO<=curO || flagO)){
            print (i-n+1,i);
            return;
        }
        flagA= (sumA<=curA); flagO= (sumO<=curO); 
    }
    print (n,N-1);
    printf ("\n");
}
/************************************/
int main(){
    scanf ("%d", &Q);
    while (Q){
        scanf ("%d", &n);
        for (int i=1, leni=2*n;i<leni;i ++)
            scanf ("%d%d", &a[i], &o[i]);
        findSet();
        Q--;
    }
    
    return 0;
}