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
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN= 1000+5;

typedef long long ll;

bool mark[maxN][maxN];
int n,m, a,b;
int mat[maxN][maxN], mini[maxN][maxN];
ll dp[maxN][maxN], sum[maxN][maxN];

struct node{
    ll val;
    int x,y;

    node (ll _val= -1, int _x=-1, int _y=-1) : val(_val), x(_x), y(_y) {}

    inline bool operator < (const node &sec) const{
        if (val!= sec.val)
            return val < sec.val;
        if (x!= sec.x)
            return x < sec.x;
        return y < sec.y;
    }

    inline void write (){
        printf ("%d %d %I64d\n", x-a+1, y-b+1, val);
    }
};
vector <node> res;
/*****************************/
inline void setRow (int row){
    deque <int> Q;
    ll total= 0;
    for (int i=1;i< b;i ++){
        while (!Q.empty() && mat[row][i] < mat[row][Q.back()])
            Q.pop_back();
        Q.push_back (i);
        total+= mat[row][i];
    }
    for (int i=b;i<= m;i ++){
        total= (total+mat[row][i]) - mat[row][i-b];
        if (!Q.empty() && Q.front()== (i-b))
            Q.pop_front();

        while (!Q.empty() && mat[row][i] < mat[row][Q.back()])
            Q.pop_back ();
        
        Q.push_back (i);
        mini[row][i]= mat[row][Q.front()];
        sum [row][i]= total;
    }
}
/***************************/
inline void setCol (int col){
    deque <int> Q;
    ll total= 0;
    for (int i=1;i< a;i ++){
        while (!Q.empty() && mini[i][col] < mini[Q.back()][col])
            Q.pop_back();
        Q.push_back(i);
        total+= sum[i][col];
    }
    for (int i=a;i<= n;i ++){
        total= (total + sum[i][col]) - sum[i-a][col];
        if (!Q.empty() && Q.front()==(i-a))
            Q.pop_front();
        while (!Q.empty() && mini[i][col] < mini[Q.back()][col])
            Q.pop_back();

        Q.push_back (i);
        dp [i][col]= total-((ll)a*b*mini[Q.front()][col]);
    }   
}
/***************************/
inline void Map (){
    vector <node> Q;
    for (int i=a;i<= n;i ++)
        for (int j=b;j<= m;j ++)
            Q.push_back (node (dp[i][j],i,j));

    sort (Q.begin(), Q.end());
    for (int i=0;i< (int)Q.size();i ++){
        int x1= Q[i].x-a+1, x2= Q[i].x;
        int y1= Q[i].y-b+1, y2= Q[i].y;
        if (!mark[x1][y1] && !mark[x1][y2] && !mark[x2][y1] && !mark[x2][y2]){
            res.push_back (Q[i]);
            for (int ii= x1;ii<= x2;ii ++)
                for (int jj=y1;jj<= y2;jj ++)
                    mark[ii][jj]= true;
        }
    }
}
/***************************/
int main (){
    scanf ("%d%d %d%d", &n, &m, &a, &b);
    for (int i=1;i<= n;i ++)
        for (int j=1;j<= m;j ++)
            scanf ("%d", &mat[i][j]);
    
    for (int i=1;i<= n;i ++)
        setRow (i);
    for (int i=b;i<= m;i ++)
        setCol (i);

    Map ();
    cout << res.size() << endl;
    for (int i=0;i< (int)res.size();i ++)
        res[i].write();

    return 0;
}