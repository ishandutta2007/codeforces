#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1508

int N,S[MAXN],mom[MAXN],num[MAXN];
vector <int> con[MAXN],arr;
queue <int> que;

struct Z{
    int y,x,n;
    double ang;
    bool operator < (const Z &b)const{
        return ang<b.ang;
    }
} A[MAXN];

void dfs(int n,int a,int b)
{
    int i,k,p=a;
    for (i=a+1;i<=b;i++) if (A[a].y > A[i].y) swap(A[a],A[i]);
    num[A[a].n] = n;
    for (i=a+1;i<=b;i++){
        A[i].ang = atan2(double(A[i].y-A[a].y),double(A[i].x-A[a].x));
    }
    sort(A+a+1,A+b+1);
    for (i=con[n].size();i--;){
        k = con[n][i];
        if (mom[k] != n) continue;
        dfs(k,p+1,p+S[k]); p += S[k];
    }
}

int main()
{
    int i,j,k,q;
    scanf("%d",&N);
    for (i=1;i<N;i++){
        scanf("%d%d",&j,&k);
        con[j].push_back(k), con[k].push_back(j);
    }
    for (i=1;i<=N;i++){
        scanf("%d%d",&A[i].x,&A[i].y); A[i].n = i;
    }
    mom[1] = 1;
    que.push(1);
    while (!que.empty()){
        q = que.front(); que.pop();
        arr.push_back(q);
        for (i=con[q].size();i--;){
            k = con[q][i];
            if (mom[k]) continue;
            mom[k] = q;
            que.push(k);
        }
    }
    for (i=N;--i;){
        S[arr[i]]++;
        S[mom[arr[i]]] += S[arr[i]];
    }
    dfs(1,1,N);
    for (i=1;i<=N;i++) printf("%d ",num[i]);
}