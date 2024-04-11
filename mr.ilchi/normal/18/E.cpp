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
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN= 500+5;
const int maxP= 26+3;

char mat[maxN][maxN];
int n,m, cur, oth;
int tedad[2][maxP];
int dp[2][maxP][maxP];

struct node{
    int x,y;

    node (int _x=-1, int _y=-1) : x(_x), y(_y) {}

    inline bool operator < (const node &sec) const{
        return dp[oth][x][y] < dp[oth][sec.x][sec.y];
    }

}par[maxN][maxP][maxP];
/*************************************/
inline void setDyn (){
    vector <node> Q;
    for (int i=1;i<= 26;i ++)
        for (int j=1;j<= 26;j ++) if (i!=j)
            Q.push_back (node(i,j));

    cur=1, oth=0;
    for (int i=1;i<= m;i ++)
        tedad[i&1][(int)mat[1][i]] ++;
    for (int i=1;i<= 26;i ++)
        for (int j=1;j<= 26;j ++) if (i!=j)
            dp[cur][i][j]= m - (tedad[1][i] + tedad[0][j]);  
    
    for (int o=2;o<= n;o ++){
        swap (cur,oth);
        sort (Q.begin(), Q.end());

        memset (tedad[0], 0, sizeof tedad[0]);
        memset (tedad[1], 0, sizeof tedad[1]);
        
        for (int i=1;i<= m;i ++)
            tedad[i&1][(int)mat[o][i]] ++;
        
        for (int i=1;i<= 26;i ++)
            for (int j=1;j<= 26;j ++) if (i!=j){
                int diff= m- (tedad[1][i] + tedad[0][j]);
                for (int z=0; true ;z ++){
                    if (Q[z].x!=i && Q[z].y!=j){
                        dp [cur][i][j]= diff + dp[oth][Q[z].x][Q[z].y];
                        par[ o ][i][j]= Q[z];  
                        break;
                    }       
                }
            }
    }
}
/***********************************/
inline void init (){
    for (int i=1;i<= n;i ++)
        for (int j=1;j<= m;j ++)
            mat[i][j]-= 'a'-1;  
}
/***********************************/
inline void print (int row, node v){
    if (row==0)
        return;

    for (int i=1;i<= m;i+=2){
        mat[row][i]= v.x+'a'-1;
        mat[row][i+1]= v.y+'a'-1;
    }
    if (m&1)
        mat[row][m+1]= 0;
    print (row-1, par[row][v.x][v.y]);
}
/***********************************/
int main(){
    scanf ("%d%d", &n, &m);
    for (int i=1;i<= n;i ++)
        scanf (" %s", &mat[i][1]);

    init ();
    setDyn ();
    int res= n*m + 1;
    node fin;
    for (int i=1;i<= 26;i ++){
        for (int j=1;j<= 26;j ++) if (i!=j)
            if (dp[n&1][i][j] < res){
                res= dp[n&1][i][j];
                fin= node (i,j);
            }   
    }
    printf ("%d\n", res);
    print (n,fin);
    for (int i=1;i<= n;i ++)
        puts (&mat[i][1]);

    return 0;
}