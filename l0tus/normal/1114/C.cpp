#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5;
long long N,K,A[MN],B[MN],cnt,val,res,ans=1e18,num[MN];
bool prime[MN];
vector<long long> P;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    val = K;
    for(int i=0; i<MN; i++) prime[i] = 1;
    for(long long i=2; i<=K/i; i++){
        if(!prime[i]) continue;
        for(long long j=2; j*i*j*i<=K; j++) prime[j*i] = false;
        if(K%i==0){
            P.push_back(i);
            while(val%i==0){
                num[cnt]++;
                val/=i;
            }
            cnt++;
        }
    }
    if(val!=1){
        P.push_back(val);
        num[cnt] = 1;
        cnt++;
    }
    for(int i=0; i<P.size(); i++){
        val = N;
        res = 0;
        while(val){
            val/=P[i];
            res += val;
        }
        ans = min(ans,res/num[i]);
    }
    cout << ans;
}