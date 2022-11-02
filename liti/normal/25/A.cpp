//In the name of Allah
#include <iostream>
using namespace std;

int cnt[2];
int last[2];

int main() { 
 int n;
 cin >> n;
 for( int i = 0 ; i < n ; i++ ) { 
   int num;
   cin >> num;
   cnt[num%2]++;
   last[num%2] = i + 1; 
 }
 cout << (cnt[0]==1?last[0]:last[1]) << endl;
}