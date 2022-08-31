#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[2*n];
    int q[2*n];
    int cur = 1;
    int k[3];
    k[1] = k[2] = 0;
    for(int i = 0; i < 2*n; i++) cin >> a[i];
    for(int i = 0; i < 2*n; i++) q[i] = 0;
    for(int i = 10; i <= 99; i++){
        int r = 0;
        for(int j = 0; j <2* n; j++){
            if(a[j] == i){
                r++;
            }   
        }
        if(r == 1){
            for(int j = 0; j < 2*n; j++){
                if(a[j] == i){
                    q[j] = cur;
                    k[cur]++;
                    cur = 3-cur;
                }
            }
        } else if(r > 1){
            int f = 0;
            int s = 0;
            for(int j = 0; j < 2*n; j++){
                if(a[j] == i){
                    if(f == 0){
                        f = 1;
                        q[j] = 1;
                        k[1]++;
                    } else if(s == 0){
                        s = 1;
                        q[j] = 2;
                        k[2]++;
                    }
                }
            }
        }
        
    }
    for(int i = 0; i < 2*n; i++){
        if(q[i] == 0){
            if(k[1] < n){
                q[i] = 1;
                k[1]++;
            } else {
                q[i] = 2;
                k[2]++;
            }
        }
    }
    set<int> stuff[3];
    for(int i = 0; i < 2*n; i++){
        stuff[q[i]].insert(a[i]);
    }
    cout << stuff[1].size()*stuff[2].size() << endl;
    for(int i = 0; i < 2*n; i++){
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}