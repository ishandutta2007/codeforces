#include <bits/stdc++.h>
using namespace std;

string ss[2] = {"NO","YES"};

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n], b[n], c[n];
        for(int i=0;i<n;i++)
            cin>>a[i], c[i] = 0;
        for(int i=0;i<n;i++)
            cin>>b[i];
        bool pass = (a[n-1] == b[n-1]);
        int pt1 = n-2;
        for(int i=n-2;i>=0;i--) {
            if(!pass) break;
            if(b[i] != b[i+1]) {
                while(pt1>=0 && a[pt1] != b[i] && c[a[pt1]] != 0) {
                    c[a[pt1]]--;
                    pt1--;
                }
                if(pt1 < 0) {
                    pass = false;
                    continue;
                }
                pass = (a[pt1] == b[i]);
            }
            c[b[i]]++;
        }
        if(pass)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}