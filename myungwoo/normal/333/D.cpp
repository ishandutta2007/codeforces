#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,K,A[1001][1001],ans;
vector <int> arr[1001];
bool V[1001][1001];

struct Z{
    Z(int x=0,int y=0): x(x), y(y) {}
    int x,y;
    bool operator < (const Z &ot)const{
        return A[y][x] < A[ot.y][ot.x];
    }
}; vector<Z> order;

int main()
{
    int i,j,y,x,a,b;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j), order.push_back(Z(j,i));
    sort(order.begin(),order.end());
    for (i=order.size();i--;){
        y = order[i].y, x = order[i].x;
        for (j=arr[x].size();j--;){
            a = arr[x][j];
            b = y;
            if (V[a][b]){ printf("%d\n",A[y][x]); return 0; }
            V[a][b] = V[b][a] = 1;
        }
        arr[x].push_back(y);
    }
}