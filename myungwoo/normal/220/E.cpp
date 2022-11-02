#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define TS 262144
typedef long long lld;

int N,A[MAXN];
lld K,ans;
int tree1[TS],tree2[TS],ST=TS/2-1;
vector <int> arr;

inline int search(int tree[TS],int l,int r)
{
    int ret=0;
    for (;l<=r;l>>=1,r>>=1){
        if (l&1) ret += tree[l++];
        if (!(r&1)) ret += tree[r--];
    }
    return ret;
}

inline void reg(int tree[TS],int n,int v)
{
    for (;n;n>>=1) tree[n] += v;
}

int main()
{
    int i,j,k,v;
    lld now=0;
    scanf("%d%I64d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i), arr.push_back(A[i]);
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    for (i=1;i<=N;i++) A[i] = lower_bound(arr.begin(),arr.end(),A[i])-arr.begin()+1;
    for (i=1,k=N;i<=N;i++){
        now += search(tree1,ST+A[i]+1,ST+N)+search(tree2,ST+1,ST+A[i]-1);
        reg(tree1,ST+A[i],1);
        while (k > i){
            v = search(tree1,ST+A[k]+1,ST+N)+search(tree2,ST+1,ST+A[k]-1);
            if (now+v > K) break;
            now += v;
            reg(tree2,ST+A[k],1);
            k--;
        }
        while (now > K || k < i){
            if (k >= N) break;
            ++k;
            v = search(tree1,ST+A[k]+1,ST+N)+search(tree2,ST+1,ST+A[k]-1);
            reg(tree2,ST+A[k],-1);
            now -= v;
        }
        if (now <= K) ans += N-k;
    }
    printf("%I64d",ans);
}