#include<bits/stdc++.h>

using namespace std;

int main(){
int n;
cin >> n;
int a[n];
for(int i = 0; i < n; i++) cin >> a[i];
set<int> ab;
for(int i = 0; i < n; i++){
if(a[i] <= n) ab.insert(a[i]);
}
set<int> c;
for(int i = 1; i <= n; i++){
if(ab.find(i) == ab.end()){
c.insert(i);
}
}

for(int i = 0; i < n; i++){
if(ab.find(a[i]) != ab.end()){
ab.erase(a[i]);
} else {
a[i] = *c.begin();
c.erase(c.begin());
}
}
for(int i = 0; i < n; i++) cout << a[i] << " ";
cout << endl;




}