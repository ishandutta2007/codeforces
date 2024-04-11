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

int N, M, K;
int A[MAXN][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++) cin >> A[i][j];
    }
    int left = 0, right = -1;
    deque <int> dq[6];
    for (int l=1,r=1;r<=N;r++){
        for (int i=1;i<=M;i++){
            while (!dq[i].empty() && A[dq[i].back()][i] <= A[r][i]) dq[i].pop_back();
            dq[i].push_back(r);
        }
        for (;l<=r;){
            int sum = 0;
            for (int i=1;i<=M;i++){
                sum += A[dq[i].front()][i];
            }
            if (sum <= K) break;
            for (int i=1;i<=M;i++){
                while (!dq[i].empty() && dq[i].front() <= l) dq[i].pop_front();
            }
            l++;
        }
        if (right-left+1 < r-l+1)
            left = l, right = r;
    }
    vector <int> ans(M+1, 0);
    for (int i=left;i<=right;i++){
        for (int j=1;j<=M;j++) put_max(ans[j], A[i][j]);
    }
    for (int i=1;i<=M;i++) cout << ans[i] << " ";
    cout << endl;
}