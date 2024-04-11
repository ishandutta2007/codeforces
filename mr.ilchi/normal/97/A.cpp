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
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxN = 30 + 5;

char mat [maxN][maxN];
bool vis[maxN][maxN] , check[maxN][maxN];
int n,m;
int cnt[maxN];
int ans[maxN][maxN] , sol[maxN][maxN] , mark[maxN][maxN];
pii match[maxN][maxN];
vector <pii> Q;

int dx[] = {0,0,1,1};
int dy[] = {0,1,0,1};

inline void parse (){

    Q.push_back (pii(0,0));
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) if (mark[i][j]==0 && mat[i][j]!='.'){
            Q.push_back (pii(i,j));
            mark[i][j] = mark[i][j+1] = mark[i+1][j] = mark[i+1][j+1] = (int)Q.size()-1;
        }

    int mx[]= {-1,1,0,0};
    int my[]= {0,0,1,-1};
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) if (mat[i][j]!='.'){
            
            for (int z=0; z<4; z++){
                
                int xx = i + mx[z];
                int yy = j + my[z];

                if (mat  [i][j]== mat[xx][yy])
                    match[i][j] = pii(xx, yy);
            }
        }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) if (mat[i][j]!='.'){

            int xx = match[i][j].first;
            int yy = match[i][j].second;
            
            if (mark [i][j]!= mark[xx][yy])
                (mark[i][j] > mark[xx][yy]) ? check[i][j]=true : check[xx][yy]=true;

            else
                (pii(i,j) < pii(xx,yy)) ? check[i][j]=true : check[xx][yy]=true;
        }
}

inline bool add (int poi , int val){

    int x = Q[poi].first , y = Q[poi].second;

    for (int i=0; i<4; i++)
        ans[x+dx[i]][y+dy[i]] = val;

    vector <pii> t;

    for (int i=0; i<4; i++){
        
        int xx = x+dx[i];
        int yy = y+dy[i];

        if (!check[xx][yy]) continue;
            
        int tmp = ans[match[xx][yy].first][match[xx][yy].second];

        if (vis[min(val,tmp)][max(val,tmp)])
            return false;

        t.push_back (pii(min(val,tmp),max(val,tmp)));
    }
    
    for (int i=0;i<(int)t.size();i++)
        for (int j=i+1;j<(int)t.size();j++) if (t[i]==t[j])
            return false;

    for (int i=0;i<(int)t.size();i++)
        vis[t[i].first][t[i].second] = true;

    return true;
}

inline void CL (int poi , int val){
    
    for (int i=0; i<4; i++){

        int xx = Q[poi].first  + dx[i];
        int yy = Q[poi].second + dy[i];

        if (!check[xx][yy]) continue;
    
        int tmp = ans[match[xx][yy].first][match[xx][yy].second];

        vis[min(val,tmp)][max(val,tmp)] = false;
    }
}

inline int btrack (int poi){
    
    if (poi==15){
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                sol[i][j] = ans[i][j];

        return 1;
    }

    int emp=0,fir=-1;

    for (int i=0; i<=6; i++) { emp+= (cnt[i]==0); fir=(cnt[i]==0) ? i : fir; }

    int ret=0;

    if (fir!=-1 && add(poi,fir)){
        cnt[fir]++;
        ret+= emp * btrack(poi+1);
        CL(poi,fir);
        cnt[fir]--;
    }

    for (int i=0;i<=6;i++) if (cnt[i]>0 && cnt[i]<2 && add(poi,i)){
        cnt[i]++;
        ret+=btrack(poi+1);
        CL(poi,i);
        cnt[i]--;
    }

    return ret;
}

int main(){
    
    cin >> n >> m;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> mat[i][j];

    parse();

    cout << btrack (1) << endl;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) 

            if (mat[i][j]=='.')
                cout << '.';
            else
                cout << sol[i][j];

        cout << endl;
    }
    return 0;
}