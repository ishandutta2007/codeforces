#include <bits/stdc++.h>
using namespace std;

multiset <int> ans;

int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
   int n;
   cin>>n;
   string a;
   cin>>a;
   for ( int i = 0; i < a.size(); i++) {
    if ( a[i] - '0' != 0 && a[i] - '0' != 1) {
        ans.insert( a[i] - '0');
    }
   }
   bool mark = true;
   while ( mark ) {
        mark = false;
        for ( multiset < int > :: iterator it = ans.begin(); it != ans.end(); it++) {
             int a = *it;
             if ( a == 9) {
                mark = true;
                ans.erase(it);
                ans.insert(7);
                ans.insert(3);
                ans.insert(3);
                ans.insert(2);
                break;
             }
             if ( a == 8) {
                mark = true;
                ans.erase(it);
                ans.insert(7);
                ans.insert(2);
                ans.insert(2);
                ans.insert(2);
                break;
             }
             if ( a == 6) {
                mark = true;
                ans.erase(it);
                ans.insert(5);
                ans.insert(3);
                break;
             }
             if ( a == 4) {
                mark = true;
                ans.erase(it);
                ans.insert(3);
                ans.insert(2);
                ans.insert(2);
                break;
             }
        }
   }
   int b[2000];
   int i = 0;
   for ( multiset <int > :: iterator it = ans.begin(); it != ans.end(); it++) {
       b[i] = *it;
       i++;
   }
   for ( int j = 0; j < i; j++) {
        cout<<b[ i - 1 - j];
   }
   return 0;
}