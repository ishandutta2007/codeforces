#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
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
void pre(){}
vector<vector<ll>> mult(vector<vector<ll>> &a,vector<vector<ll>> &b){
    vector<vector<ll>>ret = a;
    int n = a.size();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){ 
            ret[i][j] = 0; 
            for(int k = 0; k < n; k++) 
                ret[i][j] = add(ret[i][j],mul(a[i][k],b[k][j])); 
        } 
    } 
    return ret;
}
vector<vector<ll>> matrix_expo(vector<vector<ll>> x,ll y){
    vector<vector<ll>> res = x;
    int n = x.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) res[i][j]=1;
            else res[i][j]=0;
        }
    }
    while (y > 0){   
        if (y & 1)  
            res = mult(res,x);  
        y = y>>1;
        x = mult(x,x); 
    }  
    return res;
}
void solve(){
    ll n,k;cin>>n>>k;
    ll arr[n];
    ll brr[n];
    ll a = 0 , b = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
        if(arr[i]==1){
            a++;
        }else{
            b++;
        }
    }
    int oo = min(a,b);
    oo++;
    vector<vector<ll>>x(oo);
    for (int i = 0; i < oo; i++)
        x[i].resize(oo);
    for(int i=0;i<oo;i++){
        for(int j = 0;j<oo;j++){
            if(i == j-1){
                x[i][j] = (j)*(j); 
            }else if(i == j ){
                x[i][j] = (a*(a-1))/2 + (b*(b-1))/2 + (j)*(n-2*(j));
            }else if( i == j+1 ){
                x[i][j] = (a-j)*(b-j);
            }else{
                x[i][j]=0;
            }
            //cout<<x[i][j]<<" ";
        }
        //cout<<"\n";
    }
    //cout<<oo<<"\n";cout.flush();
    x = matrix_expo(x,k);
    sort(brr,brr+n);
    int op = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=brr[i]){
            op++;
        }
    }
    op/=2;
    cout<<divi(x[0][op],power((n*(n-1))/2,k))*(1/1)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}