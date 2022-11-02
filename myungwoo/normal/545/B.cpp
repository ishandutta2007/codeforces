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

#define MAXN 100005

int N;
char A[MAXN], B[MAXN];
char C[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> A+1 >> B+1; N = strlen(A+1);
    bool sw = 0;
    for (int i=1;i<=N;i++){
        if (A[i] == B[i]){
            C[i] = A[i];
        }else{
            if (sw) C[i] = B[i];
            else C[i] = A[i];
            sw ^= 1;
        }
    }
    if (sw) puts("impossible");
    else puts(C+1);
}