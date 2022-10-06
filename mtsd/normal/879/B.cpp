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

long long  mod = 1000000007;

int main(){
    ll n,k;
    cin >> n >> k;
    queue<int> q;
    vector<int>  v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    } 
    if(k >= n){
        cout << *max_element(v.begin(),v.end()) << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        q.push(v[i]);
    }
    int x = 0;
    int ans;
    int a,b;
    a = q.front();
    q.pop();
    while(1){
        if(x==k){
            ans = a;
            break;
        }
        b = q.front();
        q.pop();
        if(a>b){
            x++;
            q.push(b);
        }else{
            x=1;
            q.push(a);
            a = b;
        }
    }
    cout << ans << endl;
    return 0;
}