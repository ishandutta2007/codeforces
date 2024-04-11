#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
ll num[1000005],num2[1000005],sum[1000005],cur,pre,head,tail,ans;
string S[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll N,L;
    cin >> N;
    ans = N*N;
    for(int i=0; i<N; i++){
        cin >> L;
        bool ch = 1;
        pre = 1000001;
        while(L--){
            cin >> cur;
            if(pre==1000001) head = cur;
            if(cur>pre) ch = 0;
            pre = cur;
            if(L==0) tail = cur;
        }
        if(ch){
            num[head]++;
            num2[tail]++;
        }
    }
    sum[0] = num[0];
    for(int i=0; i<=1000000; i++){
        if(i>0) sum[i] = num[i] + sum[i-1];
        ans -= num2[i]*sum[i];
    }
    cout << ans;
}