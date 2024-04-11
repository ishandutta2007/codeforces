#include <iostream>
#include <string.h>
using namespace std;
int Abs(int n){
if (n < 0) return -n;
return n;
}
int main(){
int n;
cin >> n;
int t[n];
for(int i = 0; i < n; i++){
cin >> t[i];
}
int a = 0;
a = t[0]+1;
for(int i = 1; i < n; i++){
a += Abs(t[i]-t[i-1]);
a += 2;
}
cout << a << endl;
return 0;
}