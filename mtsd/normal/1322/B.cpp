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

template<typename T> class BIT {
private:
	int n;
	vector<T> bit;
public:
	// 0_indexed  i  x 
	void add(int i, T x){
		i++;
		while(i < n){
			bit[i] += x, i += i & -i;
		}
	}
	// 0_indexed  [0,i] ()
	T sum(int i){
		i++;
		T s = 0;
		while(i > 0){
			s += bit[i], i -= i & -i;
		}
		return s;
	}
	BIT(){}
	//0
	BIT(int sz) : n(sz+1), bit(n, 0){}
	BIT(vector<T>& v) : n((int)v.size()+1), bit(n, 0){
		for(int i = 0; i < n-1; i++){
			add(i,v[i]);
		}
	}
	void print(){
		for(int i = 0; i < n-1; i++){
			cout<<sum(i)-sum(i-1)<< " ";
		}
		cout<<endl;
	}
	//-1
	void print_sum(){
		for(int i = 0; i < n; i++){
			cout<<sum(i-1)<<" ";
		}
		cout<<endl;
	}
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<BIT<int> > bit(25);
    rep(i,25){
        bit[i] = BIT<int>(1<<(i+1));
    }
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int cnt[30]={};
    rep(j,25){
        int mask = (1<<(j+1));
        for(int i=n-1;i>=0;i--){
            int k = a[i]%mask;
            cnt[j] += (bit[j].sum(mask-k-1) - bit[j].sum(mask/2-k-1));
            
            cnt[j] %= 2;
            cnt[j] += (bit[j].sum(min(4*(1<<j)-k-1,(1<<(j+1))-1)) - bit[j].sum(min(3*(1<<j)-k-1,(1<<(j+1))-1)));
            cnt[j] %= 2;
            bit[j].add(k,1);
        }
    }
    int res = 0;
    rep(i,25){
        if(cnt[i]==1){
            res ^=(1<<i); 
        }
    }
    cout << res << endl;
    return 0;
}