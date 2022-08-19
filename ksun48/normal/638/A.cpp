#include<bits/stdc++.h>
using namespace std;

int main(){
int n, m;
cin >> n >> m;
if(m % 2 == 1){
cout << (m+1)/2 << endl;
} else {
cout << ((n+1)-m+1)/2 << endl;
}

}