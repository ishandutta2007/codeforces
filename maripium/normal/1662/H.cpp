#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF= 1LL<<52;
const int MAXN = 2e5+9;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int a,b;cin >> a >> b;
        vector<int> ans;
        array<int,5> tst{__gcd(a-1,b-1),__gcd(a,b-2),__gcd(a-2,b),__gcd(__gcd(a,a-2),b-1),__gcd(__gcd(b,b-2),a-1)};
        for(int i:tst){
            for(int j=1;(ll)j*j<=i;j++){
                if(i%j==0){
                    ans.push_back(j);
                    ans.push_back(i/j);
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.resize(unique(ans.begin(),ans.end())-ans.begin());
        cout << ans.size();
        for(int i:ans)cout << ' ' << i ;
        cout << endl;
    }
}