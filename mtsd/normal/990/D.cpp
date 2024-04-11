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

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a!=1&&b!=1){
        cout << "NO" << endl;
        return 0;
    }
    if(a==1&&b==1){
        if(n==2||n==3){
            cout << "NO" << endl;
            return 0;
        }
        vector<vector<int> > v(n,vector<int>(n));
        for(int i=0;i<n-1;i++){
            v[i][i+1]=1;
            v[i+1][i] = 1;
        }
        cout << "YES" << endl;
        rep(i,n){
            rep(j,n){
                printf("%d",v[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    if(b==1){
        vector<vector<int> > v(n,vector<int>(n));
        for(int i=0;i<n-a;i++){
            v[i][i+1]=1;
            v[i+1][i] = 1;
        }
        cout << "YES" << endl;
        rep(i,n){
            rep(j,n){
                printf("%d",v[i][j]);
            }
            printf("\n");
        }
    }else{
        vector<vector<int> > v(n,vector<int>(n));
        for(int i=0;i<n-b;i++){
            v[i][i+1]=1;
            v[i+1][i] = 1;
        }
        cout << "YES" << endl;
        rep(i,n){
            rep(j,n){
                if(i==j)printf("0");
                else if(v[i][j]==1)printf("0");
                else printf("1");
            }
            printf("\n");
        }

    }
    
    return 0;
}