#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        int yes = 1;
        for(int j = 0; j <= k; j++){
            int t = r;
            int yes2 = 0;
            while(t>0){
                if(t % 10 == j){
                    yes2 = 1;
                }
                t = t/10;
            }
            if(yes2 == 0){
                yes = 0;
            }
        }
        if(yes) ans++;
    }
    cout << ans << endl;
    // your code goes here
    return 0;
}