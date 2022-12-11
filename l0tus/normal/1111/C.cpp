#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1e5+5;
const int INF = 1e9;
ll N,K,A,B,X[MAX],cnt,sum,ans;

ll act(int s, int e)
{
    int m = (s+e)/2;
    int num = upper_bound(X,X+K,e) - lower_bound(X,X+K,s);
    ll res;
    if(num) res = B*num*(e-s+1);
    else res = A;
    if(s==e || num==0) return res;
    return min(act(s,m)+act(m+1,e),res);
}

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K >> A >> B;
    for(int i=0; i<K; i++) cin >> X[i];
    sort(X,X+K);
    cout << act(1,1<<N);
}