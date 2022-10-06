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
	map<int,int> bit;
public:
	// 0_indexed  i  x 
	void add(int i, T x){
		i++;
		while(i < 1000000001){
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
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<pair<int,int> >P;

        rep(i,n){
            int a,b;
            cin >> a >> b;
            P.push_back({a,b});
        }
        sort(all(P));
        int right = 0;
        int mx = 0;
        BIT<int> bit;
        int ans = 0;
        rep(i,n){
            if(P[i].second < mx){
                bit.add(P[i].second,1);
                continue;
            }
            mx = P[i].second;
            while(right<n){
                if(P[right].first <= mx){
                    right++;
                }else{
                    break;
                }
            }
            int res = bit.sum(1000000000) - bit.sum(P[i].first-1);
            bit.add(P[i].second,1);
            chmax(ans,res + right - i);
            // cerr << i << " " << res << " " << right << endl;
        }
        cout << n-ans << "\n";
    }
    return 0;
}