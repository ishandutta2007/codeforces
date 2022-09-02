#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int pr[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int d[101][1<<16];
int b[101][1<<16];
int chk[1<<16][60];
int p[101];
int ord[101];
int C[101];

bool comp(const int &a, const int &b){return p[a] < p[b];}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",p+i);
    for(i=1;i<=n;i++)ord[i] = i;
    sort(ord+1, ord+1+n, comp);
    for(i=n;i>n-16 && i>=1;i--){
        C[ord[i]] = 1;
    }
    for(i=0;i<1<<16;i++)d[0][i] = 1e8;
    d[0][0] = 0;
    for(i=0;i<1<<16;i++){
        int j;
        for(j=1;j<59;j++){
            int k;
            for(k=0;k<16;k++){
                if((1<<k & i) && j % pr[k] == 0)break;
            }
            if(k != 16)chk[i][j] = 1;
        }
    }
    int q[20], top = 0;
    for(i=1;i<=n;i++)if(C[i])q[++top] = p[i];
    for(i=0;i<top;i++){
        int j;
        for(j=0;j<1<<16;j++)d[i+1][j] = 1e8;
        for(j=0;j<1<<16;j++){
            if(d[i][j] == 1e8)continue;
            for(int k=1;k<q[i+1]+q[i+1];k++){
                if(chk[j][k] || k == 59)continue;
                int bit = j;
                for(int u=0;u<16;u++){
                    if(k % pr[u] == 0)bit |= 1<<u;
                }
                if(d[i+1][bit] > d[i][j] + abs(k - q[i+1]))d[i+1][bit] = d[i][j] + abs(k - q[i+1]), b[i+1][bit] = k;
            }
        }
    }
    int start = 0;
    for(i=0;i<1<<16;i++)if(d[top][i] < d[top][start])start = i;
    int ans[101], tp = 0;
    for(i=top;i;i--){
        ans[tp++] = b[i][start];
        int u = b[i][start];
        for(int t=0;t<16;t++){
            if(u % pr[t] == 0)start ^= 1<<t;
        }
    }
    int A[101];
    vector <int> v;
    for(i=1;i<=n;i++)if(C[i])v.push_back(i);
    for(i=tp-1;i>=0;i--)A[v[i]] = ans[tp-1-i];
    for(i=1;i<=n;i++)if(!C[i])A[i] = 1;
    for(i=1;i<=n;i++)printf("%d ",A[i]);
    return 0;
}