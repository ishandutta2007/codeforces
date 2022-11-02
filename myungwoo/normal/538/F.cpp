#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 200005

int N;
int A[MAXN], S[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d", A+i);
    for (int i=1;i<N;i++){
        int sqrt = 0;
        for (int j=1;j*j<=i-1;j++) sqrt = j;
        vector <int> arr;
        for (int j=0;j<=sqrt;j++) arr.pb(j);
        for (int j=1;j<=sqrt;j++) arr.pb((i-1)/j);
        sort(all(arr));
        arr.erase(unique(all(arr)), arr.end());
        for (int p: arr) if (A[p] > A[i]){
            int l = (i-1)/(p+1)+1, r = p ? (i-1)/p : N-1;

            S[l]++; S[r+1]--;
        }
    }
    for (int i=1;i<N;i++) S[i] += S[i-1], printf("%d ", S[i]); puts("");
}