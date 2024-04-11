#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int num[110000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 110000; i++){
        num[i] = 0;
    }
    int depth[n];
    depth[0] = 0;
    for(int i = 0; i < n; i++){
        if(i > 0){
            int a;
            cin >> a;
            a--;
            depth[i] = depth[a]+1;
        }
        num[depth[i]] ^= 1;
    }
    int ans = 0;
    for(int i = 0; i <= 110000; i++){
        ans += num[i];
    }
    cout << ans << endl;
}