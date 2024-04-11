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

int N;
int cnt[26];
char A[100005];

int main()
{
    scanf("%d%s", &N, A+1);
    for (int i=1;i<=N;i++) cnt[A[i]-'A']++;
    int mx = -1, mxc = 0;
    for (int i=0;i<26;i++){
        if (cnt[i] > mx)
            mx = cnt[i], mxc = 1;
        else if (cnt[i] == mx)
            mxc++;
    }
    int MOD = 1e9 + 7;
    int ans = 1;
    for (int i=0;i<N;i++) ans = (lld)ans * mxc % MOD;
    printf("%d\n", ans);
}