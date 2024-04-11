#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int d[n];
        long long ans = 0, sum = 0, maxi = 0;
        for(int i=0;i<n;i++) {
            cin>>d[i];
        }
        sort(d,d+n);
        for(int i=1;i<n;i++) {
            ans -= (d[i] - d[i-1]);
            ans += 1LL*i*d[i];
            ans -= sum;
            sum += d[i];
        }
        cout<<-ans<<endl;
    }
    return 0;
}