//In the  name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
 int n;
 cin >> n;
 int sum = 0;
 for( int i = 0 ; i < n ; i++ ) { 
   int num; cin >> num; sum += num;
 }
 cout << fixed << setprecision(5) << sum / double(n) << endl;
}