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

int main(){
    int n;
    cin >> n;
    int x;
    for(int i=0;i<1000;i++){
        if(i*i>=n){
            x = i;
            break;
        }
    }
    vector<int> a(n);
    int p = x;
    for(int i=n-1;i>=0;i--){
        a[i] = p;
        p--;
        if((n-1-i+1)%x==0){
            p+=2*x;
        }
        if(p>n){
            p=n;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}