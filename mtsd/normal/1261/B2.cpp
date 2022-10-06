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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<int,int> > b;
    rep(i,n){
        b.push_back(MP(a[i],-i));
    }
    sort(b.begin(),b.end(),greater<pair<int,int> > ());
    
    int m;
    cin >> m;
    vector<pair<pair<int,int>,int> > query;
    rep(i,m){
        int aa,bb;
        cin >> aa >> bb;
        query.push_back(MP(MP(aa,bb),i));
    }
    sort(query.begin(),query.end());
    int q1 = 0;
    BIT<int> bit(n);
    vector<int> res(m);
    rep(i,m){
        int qid = query[i].second;
        int k = query[i].first.first;
        int pos = query[i].first.second;
        while(k>q1){
            int ss = -b[q1].second;
            bit.add(ss,1);
            q1++;
        }
        int ok = n-1;
        int ng = -1;
        while(ok-ng>1){
            int mid = (ok+ng)/2;
            if(bit.sum(mid) >= pos){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        res[qid] = a[ok];
    }
    rep(i,m){
        cout << res[i] << "\n";
    }
    return 0;
}