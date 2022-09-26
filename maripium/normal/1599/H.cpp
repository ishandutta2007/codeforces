#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1200005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s;
    cout<<"? 1 1"<<endl;
    cin>>s;
    int x = 1;
    for(int i = 29; i >= 0; --i){
        if(x + (1 << i) > 1000000000)
            continue;
        cout<<"? "<<x + (1 << i)<<" 1"<<endl;
        int t;
        cin>>t;
        if(t == s - ((x + (1 << i)) - 1))
            x += (1 << i);
    }
    int x1 = x;
    int y1 = s + 2 - x1;
    cout<<"? 1 1000000000"<<endl;
    cin>>s;
    int y2 = 999999999 + x1 - s;

    cout<<"? 1000000000 1"<<endl;
    cin>>s;
    int x2 = 999999999 + y1 - s;

    cout<<"! "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
}