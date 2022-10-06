#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

long long  mod = 1000000007;

int main(){
	int n;
	double r;
	cin >> n >> r;
	vector<double> x(n),y(n);
	rep(i,n){
		cin >> x[i];
	}
	rep(i,n){
		if(i==0){
			y[0] = r;
		}else{
			double ma = 0.0;
			rep(j,i){
				if(abs(x[j]-x[i])<=2*r){
					double h = y[j] + sqrt(2*r*2*r-(x[j]-x[i])*(x[j]-x[i])); 
					ma = max(ma,h);
				}
			}
			if(ma!=0.0){
				y[i] = ma;
			}else{
				y[i] = r;
			}
		}
	}
	cout.precision(15);
	rep(i,n){
		cout << y[i];
		if(i!=n-1){
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}