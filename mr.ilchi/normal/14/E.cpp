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

using namespace std;

typedef long long ll;

const int maxN= 20+5;
const int maxL= 4*3+5;
const int maxT= 10+2;
const int maxV= 4 +2;

ll n,t,Size;
ll par[maxV][maxV];
ll dp[2][maxL][maxT][maxT];

struct node{
    int s,e;

    node(int _s=-1, int _e=-1) : s(_s), e(_e) {}

}a[maxL];
/**************************************/
inline void setDyn (){
    int cur=0, oth=1;
    for (int i=1;i<=Size;i++)
        dp[cur][i][0][0]= 1;
    for (int i=3;i<=n;i ++){
        swap (cur,oth);
        for (int j=1;j<=Size;j ++){
            int s=a[j].s, e=a[j].e;
            for (int z=1;z<=4;z++){
                if (z==e)
                    continue;
                int up=0, down=0, jj= par[e][z];
                if (s<e && z<e)
                    up= 1;
                if (e<s && e<z)
                    down= 1;
                int maxlen=(i/2);
                for (int u=up;u<=maxlen;u ++)
                    for (int d=down;d<=maxlen;d ++)
                        dp[cur][j][u][d]+= dp[oth][jj][u-up][d-down];           
            }       
        }
        for (int j=1;j<=Size;j++)
            for (int u=0;u<maxT;u ++)
                for (int d=0;d< maxT;d ++)
                    dp[oth][j][u][d]= 0;
    }
}
/**************************************/
inline void setA (){
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j ++) 
            if (i!=j){
                a[++Size]= node(i,j);
                par[i][j]= Size;
            }
}
/**************************************/
int main (){
    cin >> n >> t;
    setA ();
    setDyn ();
    ll res= 0;
    for (int j=1;j<=Size;j ++)
        res+= dp[n&1][j][t][t-1];
    cout << res << endl;

    return 0;
}