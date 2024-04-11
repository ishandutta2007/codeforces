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

int N, K, P, X, Y;
int A[1004];

int main()
{
    cin >> N >> K >> P >> X >> Y;
    int sum = 0, lower = 0;
    for (int i=1;i<=K;i++){
        cin >> A[i];
        sum += A[i];
        if (A[i] < Y) lower++;
    }
    int remain_sum = X - sum;
    if (remain_sum < N-K || lower > N/2){ puts("-1"); return 0; }
    int pos_sum = 0, remain_cnt = N-K;
    vector <int> ans;
    while (lower < N/2 && remain_cnt > 0){
        lower++; pos_sum++; remain_cnt--;
        ans.pb(1);
    }
    for (;remain_cnt > 0;remain_cnt--) ans.pb(Y), pos_sum += Y;
    if (pos_sum > remain_sum){ puts("-1"); return 0; }
    for (int v: ans) cout << v << " ";
    cout << endl;
}