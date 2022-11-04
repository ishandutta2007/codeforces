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
#include <algorithm>

using namespace std;

const int MAXN= 5000+5;
const int INF= 1000*1000*1000;

int n, card_w, card_h;
int dp[MAXN], par[MAXN];

struct rect{
    int id, w, h;

    inline bool operator < (const rect &sec) const{
        if (w!= sec.w)
            return w < sec.w;
        return h > sec.h;
    }

}a[MAXN];
/********************************/
inline void print (int v){
    if (v== 0)
        return;
    print (par[v]);
    cout << a[v].id << ' ';
}
/********************************/
inline bool cmp (const int &a1, const int &a2){
    return a[a1].h < a[a2].h;
}
/********************************/
int main (){
    cin >> n >> card_w >> card_h;
    int Size= 0;
    for (int i= 1;i<= n;i ++){
        Size ++;
        a[Size].id= i;
        cin >> a[Size].w >> a[Size].h;
        if ((card_w >= a[Size].w) || (card_h >= a[Size].h))
            Size --;
    }
    n= Size;
    sort (a+1, a+n+1);
    
    a[n+1].h= INF;
    for (int i= 1;i<= n;i ++)
        dp[i]= n+1;

    for (int i= 1;i<= n;i ++){
        int pla= lower_bound (dp, dp+n+1, i, cmp)- dp;
        dp [pla]= i;
        par[i]= dp[pla-1];
    }
    for (int i= n;i>= 0;i --)
        if (dp[i]!= (n+1)){
            cout << i << endl;
            print (dp[i]);
            cout << endl;
            break;
        }

    return 0;
}