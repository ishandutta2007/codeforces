#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define MAX_N 10005

vector<int> prime;
bool is_prime[MAX_N];

void sieve(int n){
	for(int i=0;i<=n;i++){
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime.push_back(i);
			for(int j=2*i;j<=n;j+=i){
				is_prime[j] = false;
			}
		}
	}
}

int main(){
    sieve(10000);
    // for(int i=3;i<1001;i++){
    //     bool flag = 0;
    //     for(int j=i;j<=(i+i/2);j++){
    //         if(is_prime[j])flag = 1;
    //     }
    //     if(!flag){
    //         cout << i << endl;
    //     }
    // }
    int n;
    cin >> n;
    vector<pair<int,int> > s;
    rep(i,n){
        if(i!=n-1){
            s.push_back(MP(i+1,i+2));

        }else{
            s.push_back(MP(n,1));
        }
    }
    int m = s.size();
    rep(i,n){
        if(is_prime[m])break;
        if(i%4==2||i%4==3)continue;
        if(i<n-2){
            s.push_back(MP(i+1,i+3));

        }else if(i==n-2){
            s.push_back(MP(n-1,1));
        }else{
            s.push_back(MP(n,2));
        }
        m++;
    }
    cout << m << endl;
    for(auto x:s){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}