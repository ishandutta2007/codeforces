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

int N, cnt[26];
char A[MAXN];

int main()
{
    scanf("%d%s", &N, A+1); N = N+N-2;
    int ans = 0;
    for (int i=1;i<=N;i++){
        if (islower(A[i])) cnt[A[i]-'a']++;
        else{
            if (!cnt[A[i]-'A']) ans++;
            else cnt[A[i]-'A']--;
        }
    }
    cout << ans << endl;
}