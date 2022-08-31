#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, s1, s2;
    cin >> n >> s1 >> s2;
    LL x[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    LL s = 0;
    LL e = 4123123123;
    while(s+1 < e){
        LL m = (s+e)/2;
        int ok = 1;
        if(m < abs(s1-s2)){
            ok = 0;
        }
        // can you do it in m;
        set<LL> f;
        f.insert(s1);
        LL pos = s2;
        for(int i = 0; i < n; i++){
            if(!f.empty()){
                f.insert(pos);
            }
            while(!f.empty() && (abs(*f.begin() - x[i]) > m)){
                f.erase(*f.begin());
            }
            while(!f.empty() && (abs(*f.rbegin() - x[i]) > m)){
                f.erase(*f.rbegin());
            }
            pos = x[i];
        }
        if(f.empty()) ok = 0;

        if(ok){
            e = m;
        } else {
            s = m;
        }
    }
    cout << e << endl;
}