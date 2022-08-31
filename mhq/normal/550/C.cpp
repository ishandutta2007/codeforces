#include <bits/stdc++.h>
using namespace std;


int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
   string s;
   cin>>s;
   int a[s.size()];
   int t = s.size();
   for ( int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
   }
   for ( int i = 0; i < t; i++) {
        if ( a[i] == 0) {
            continue;
        }
        for ( int j = i + 1; j < t; j++){
            for ( int k = j + 1; k < t; k++){
                 if ( (a[i] * 100 + a[j] * 10 + a[k] ) % 8 == 0 ) {
                    cout<<"YES"<<endl;
                    cout<<a[i]<<a[j]<<a[k];
                    return 0;
                 }
            }
      }
   }
   for ( int j = 0; j < t; j++) {
        if ( a[j] == 0) {
            continue;
        }
        for (int k = j + 1; k < t; k++) {
            if ( (10*a[j] + a[k]) % 8 == 0  ) {
                cout<<"YES"<<endl;
                cout<<a[j]<<a[k];
                return 0;
            }
        }
   }
   for ( int j = 0; j < t; j++) {
        if ( a[j] % 8 == 0) {
        cout<<"YES"<<endl;
        cout<<a[j];
        return 0;
       }
   }
   cout<<"NO";
   return 0;
}