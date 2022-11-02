#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int c[N];
        for(int i=0;i<N;i++) c[i] = 0;
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            c[abs(a)]++;
        }
        int sum = 0;
        for(int i=0;i<N;i++) {
            if(i == 0)
                sum += min(1,c[0]);
            else
                sum += min(2,c[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}