#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<double,int> mp;
        int counti = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == 'D')
                counti++;
            mp[(1.0*counti)/(i+1.0)]++;
            cout<<mp[(1.0*counti)/(i+1.0)]<<' ';
        }
        cout<<endl;
    }
    return 0;
}