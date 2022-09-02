#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<set>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;
typedef pair<Pi,int> Pii;

int a[8][3];
int p[8][3];
int pp[8];

set <Pii> S;

inline ll sq(int x){return (ll)x*x;}

bool dfs(int x){
    if(x == 8){
        ll a = (ll)7e18;
        int i, j;
        for(i=0;i<8;i++)for(j=i+1;j<8;j++){
            a = min(a, sq(p[i][0]-p[j][0]) + sq(p[i][1]-p[j][1])+sq(p[i][2]-p[j][2]));
        }
        S.clear();
        for(i=0;i<8;i++)S.insert(Pii(Pi(p[i][0],p[i][1]),p[i][2]));
        int mat[8][8];
        memset(mat, 0, sizeof mat);
        for(i=0;i<8;i++)for(j=0;j<8;j++){
            if(i == j)continue;
            if(sq(p[i][0]-p[j][0]) + sq(p[i][1]-p[j][1])+sq(p[i][2]-p[j][2]) == a)mat[i][j] = 1;
        }
        if(a == 0)return false;
        int cnt = 0;
        for(j=0;j<8;j++)if(mat[0][j])
            pp[cnt++] = j;
        if(cnt != 3)return false;
        for(j=0;j<3;j++){
            int t0 = pp[j];
            for(int k=0;k<j;k++){
                int t1 = pp[k];
                if((ll)(p[0][0]-p[t1][0])*(p[0][0]-p[t0][0])+(ll)(p[0][1]-p[t1][1])*(p[0][1]-p[t0][1])+(ll)(p[0][2]-p[t1][2])*(p[0][2]-p[t0][2]) != 0)return false;
            }
        }
        int qq[3][3];
        for(i=0;i<3;i++)for(j=0;j<3;j++){
            qq[i][j] = p[pp[i]][j] - p[0][j];
        }
        Pii a1 = Pii(Pi(p[0][0]+qq[0][0]+qq[1][0], p[0][1]+qq[0][1]+qq[1][1]), p[0][2]+qq[0][2]+qq[1][2]);
        if(S.find(a1) == S.end())return false;
        a1 = Pii(Pi(p[0][0]+qq[2][0]+qq[1][0], p[0][1]+qq[2][1]+qq[1][1]), p[0][2]+qq[2][2]+qq[1][2]);
        if(S.find(a1) == S.end())return false;
        a1 = Pii(Pi(p[0][0]+qq[0][0]+qq[2][0], p[0][1]+qq[0][1]+qq[2][1]), p[0][2]+qq[0][2]+qq[2][2]);
        if(S.find(a1) == S.end())return false;
        a1 = Pii(Pi(p[0][0]+qq[0][0]+qq[1][0]+qq[2][0], p[0][1]+qq[0][1]+qq[1][1]+qq[2][1]), p[0][2]+qq[0][2]+qq[1][2]+qq[2][2]);
        if(S.find(a1) == S.end())return false;
        return true;
    }
    int r[3] = {0,1,2};
    do{
        for(int i=0;i<3;i++)p[x][i] = a[x][r[i]];
        if(dfs(x+1))return true;
    }while(next_permutation(r, r+3));
    return false;
}

int main()
{
    int i, j;
    for(i=0;i<8;i++)for(j=0;j<3;j++)scanf("%d",a[i]+j);
    for(i=0;i<3;i++)p[0][i] = a[0][i];
    if(!dfs(1))printf("NO");
    else{
        printf("YES\n");
        for(i=0;i<8;i++){for(j=0;j<3;j++)printf("%d ",p[i][j]);puts("");}
    }
    return 0;
}