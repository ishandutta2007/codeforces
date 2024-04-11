#include <iostream>
using namespace std;

int main() {
int t;
cin >> t;
while(t--){
int n;
cin >> n;
string s ="";
for(int i =0;i < 110; i++)
s += 'a';

cout << s <<endl;
for(int i =0;  i < n; i++) {
int x;
cin >> x;
s[x] = char( (int(s[x] - 'a') + 1) %  26 + 'a' );
cout << s << endl;
}
}
}