#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}


// deg + 1  f(i) = val[i] (i = 0,..., deg)  f , f(num) 
//  MOD 
#define MAX_N 100005
#define MOD 1000000007

int inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - (long long)inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = (long long)fac[i-1] * i % MOD;
		finv[i] = (long long)finv[i-1] * inv[i] % MOD;
	}
}


inline int mod_pow(int a, int b)
{
	int res = 1;
	while(b){
		if(b & 1){
			res = (long long)res * a % MOD;
		}
		a = (long long)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline int add(int x,int y)
{
	return (x + y)%MOD;
}

inline int sub(int x,int y)
{
	return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
	return (long long)x*y%MOD;
}

void extgcd(int a,int b, int& x,int& y)
{
	if(b != 0){
		extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else{
		x = 1;
		y = 0;
	}
}

int mod_inverse(int a,int m)
{
	int x,y;
	extgcd(a,m,x,y);
	return (m + x % m) % m;
}

int solve(int deg, long long num, vector<int>& val)
{
	int ue = 1;
	for(int i = 0; i < deg + 1; i++){
		ue = mul(ue, sub(num % MOD, i));
	}
	int ans = 0;
	for(int i = 0; i < deg + 1; i++){
		int r1 = mul(ue, mul(mod_inverse(sub(num % MOD, i), MOD), val[i]));
		int r2 = mul(finv[deg-i], finv[i]);
		if((deg - i) % 2){
			r2 = MOD - r2;
		}
		ans = add(ans, mul(r1, r2));
	}
	return ans;
}
int comb(int a, int b)
{
    if(a<b) return 0;
    return mul(fac[a],mul(finv[b],finv[a-b]));
}

int main(){
    make();
    int n,k;
    cin >> n >> k;
    
    vector<int> p(10010);
    for(int i=1;i<=10009;i++){
        p[i] = i;
        rep(j,k-1){
            p[i] = mul(p[i],i);
        }
    }
    if(n<=2*k){
        int tmp = 0;
        for(int i=0;i<=n;i++){
            tmp = add(tmp,mul(comb(n,i),p[i]));
        }
        cout << tmp << endl;
    }else{
        int deg = k;
        long long num = n-k;
        vector<int> v;
        int two = 1;
        for(int i=k;i<=2*k;i++){
            int tmp = 0;
            for(int j=0;j<=i;j++){
                tmp = add(tmp,mul(comb(i,j),p[j]));
            }   
            v.push_back(mul(tmp,mod_inverse(two,MOD)));
            two = mul(two,2);
        }
        // rep(i,v.size()){
        //     cerr << v[i] << " ";
        // }
        // cerr << endl;
        // cout << mul(mod_pow(2,3-k),solve(k,3-k,v)) << endl;
        cout << mul(mod_pow(2,n-k),solve(k,num,v)) << endl;
    }
    return 0;
}