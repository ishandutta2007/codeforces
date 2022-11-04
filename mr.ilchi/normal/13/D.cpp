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

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxN= 500+5;

int cntR, cntB;
int Q[2*maxN];

struct node{
    ll x,y;

    node (ll _x=-1, ll _y=-1) : x(_x), y(_y) {}

    inline node operator - (const node &sec) const{
        return node (x-sec.x, y-sec.y);
    }

    inline bool operator < (const node &sec) const{
        if (y!=sec.y)
            return y < sec.y;
        return x < sec.x;
    }

    inline ll operator ^ (const node &sec) const{
        return x*sec.y - y*sec.x;
    }

    inline void read(){
        scanf ("%I64d%I64d", &x, &y);
//      cin >> x >> y;
    }
    inline void w(){
        cerr << '(' << x << ',' << y << ')' << endl;
    }

}red[maxN], blue[maxN];
/*********************************/
inline void findMin(){
    int pmin= 1;
    for (int i=2;i<= cntR;i ++){
        if (red[i] < red[pmin])
            pmin= i;
    }
    swap (red[1],red[pmin]);
}
/*********************************/
inline bool cmp (int a1, int a2){
    node &tmp1= (a1 > 0) ? red[a1] : blue[-a1];
    node &tmp2= (a2 > 0) ? red[a2] : blue[-a2];
    return (tmp1^tmp2) > 0;
}
/*********************************/
int main (){
    scanf ("%d%d", &cntR, &cntB);
    for (int i=1;i<=cntR;i ++)
        red [i].read();
    for (int i=1;i<=cntB;i ++)
        blue[i].read();
    
    int res= 0;
    while (2 < cntR){
        findMin ();
        int len=0;
        for (int i=2;i<=cntR;i ++){
            red[i] = red[i]-red[1];
            Q[len++]= i;
        }
        for (int i=1;i<=cntB;i ++){
            if (red[1] < blue[i])
                Q[len++]= -i;
            blue[i]= blue[i]-red[1];
        }
        red[1]= node (0,0);
        sort (Q, Q+len, cmp);

        for (int i=0;i< len;i ++){
            if (Q[i] < 0)
                continue;
            
            node &ii= red[Q[i]];
            int pmin= -1;
            for (int j=i+1;j< len;j ++){
                if (Q[j] < 0){
                    node &jj= blue[-Q[j]];
                    if (pmin==-1)
                        pmin= -Q[j];
                    else if (((ii-blue[pmin])^(jj-blue[pmin])) < 0)
                        pmin= -Q[j];
                }
                else{
                    if (pmin==-1)
                        res ++;
                    else if (((ii-blue[pmin])^(red[Q[j]]-blue[pmin])) < 0)
                        res ++;
                }
            }
        }
        swap (red[1],red[cntR--]);
    }
    cout << res << endl;

    return 0;
}