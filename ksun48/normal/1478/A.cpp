#include <bits/stdc++.h>

using namespace std;

int flag = 0;

int main(){
if (!flag) {
int t;
cin >> t;
flag = 1;
} else {
}
int n;
if(cin >> n){
map<int,int> x;
int y = 0;
while(n--){
int a;
cin >> a;
x[a]++;y = max(y,x[a]);
}
cout << y << '\n';
main();
}
return 0;
}