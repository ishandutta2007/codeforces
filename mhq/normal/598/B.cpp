#include <bits/stdc++.h>
using namespace std;

char s[10100];

char a [(int) 1e7];

int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
   cin>>(s+1);
   int m;
   cin>>m;
   int le,ri,k;
   int t = strlen(s + 1);
   for ( int i = 0; i < m; i++) {
        cin>>le>>ri>>k;
        for ( int j = le; j <= ri; j++) {
            a[(( j + k) - le) % ( ri - le + 1) ] = s[j];
        }
        for ( int j = 0; j<= ri - le ; j++) {
            s[le + j] = a[j];
        }
   }
   for ( int j = 1; j <=t ;j++) {
        cout<<s[j];
   }
   return 0;
}