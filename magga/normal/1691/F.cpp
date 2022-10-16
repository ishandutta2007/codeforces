#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}

long long fact[1000001];
long long ifact[1000001];
long long inverses[1000001];
void setFactorial(){
    fact[0]=1;
    ifact[0]=1;
    inverses[1]=1;
    for(int i=1;i<=1000000;i++){
        fact[i] = mul(fact[i-1],i);
        if(i>1) inverses[i] = mod - (mod/i) * inverses[mod%i] % mod;
        ifact[i] = mul(ifact[i-1],inverses[i]);
    }
}
ll ncr(ll n,ll r){
    if(n<r || r<0 || n<0) return 0;
    return mul(fact[n],mul(ifact[n-r],ifact[r]));
}
vector<int>arr[200001];
ll ans = 0;
ll curr = 0;
ll dp[200001]{0};
ll sumOfdp[200001]{0};
int sizeOfSubtree[200001]{0};
int n,k;
void dfs(int i,int from){
    sizeOfSubtree[i] = 1;
    dp[i] = 0;
    sumOfdp[i] = 0;
    for(auto to:arr[i]){
        if(to==from) continue;
        dfs(to,i);
        sumOfdp[i] = add(sumOfdp[i],sumOfdp[to]);
        dp[i] = sub(dp[i],sumOfdp[to]);
        sizeOfSubtree[i]+=sizeOfSubtree[to];
    }
    dp[i] = add(dp[i],ncr(sizeOfSubtree[i],k));
    sumOfdp[i] = add(sumOfdp[i],dp[i]);
    curr = add(curr,mul(dp[i],sizeOfSubtree[i]));
}
void transferRoot(int i,int to){
    curr = sub(curr,mul(dp[i],sizeOfSubtree[i]));
    curr = sub(curr,mul(dp[to],sizeOfSubtree[to]));
    sumOfdp[i] = sub(sumOfdp[i],add(dp[i],sumOfdp[to]));
    dp[i] = add(dp[i],sumOfdp[to]);
    dp[i] = sub(dp[i],ncr(sizeOfSubtree[i],k));
    sumOfdp[to] = sub(sumOfdp[to],dp[to]);
    dp[to] = sub(dp[to],ncr(sizeOfSubtree[to],k)); 
    sizeOfSubtree[i] -= sizeOfSubtree[to];
    sizeOfSubtree[to] += sizeOfSubtree[i];
    dp[i] = add(dp[i],ncr(sizeOfSubtree[i],k));
    sumOfdp[i] = add(sumOfdp[i],dp[i]);
    dp[to] = add(dp[to],ncr(sizeOfSubtree[to],k)); 
    dp[to] = sub(dp[to],sumOfdp[i]);
    sumOfdp[to] = add(sumOfdp[to],dp[to]);
    sumOfdp[to] = add(sumOfdp[to],sumOfdp[i]);
    curr = add(curr,mul(dp[i],sizeOfSubtree[i]));
    curr = add(curr,mul(dp[to],sizeOfSubtree[to]));
}
void dfs2(int i,int from){
    ans = add(ans,curr);
    for(auto to:arr[i]){
        if(to==from) continue;
        transferRoot(i,to);
        dfs2(to,i);
        transferRoot(to,i);
    }
}
void solve(){
    cin>>n>>k;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setFactorial();
    solve();
}