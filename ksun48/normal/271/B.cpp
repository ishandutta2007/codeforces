#include <iostream>
#include <string.h>
using namespace std;
int Abs(int n){
if (n < 0) return -n;
return n;
}
int isprime(int k){
if(k == 1) return 0;
for(int i = 2; i*i <= k; i++){
if(k % i == 0) return 0;
}
return 1;
}
int main(){
int primenum[103000];
for(int i = 1; i <= 100000; i++){
for(int j = i; j <= i+10000; j++){
if(isprime(j)){ primenum[i] = j-i;
break;
}
}
}
int n, m;
cin >> n >> m;
int num[n][m];
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
    cin >> num[i][j];
    }
}
int max1 = 500000;
for(int i = 0; i < n; i++){
    int numprime = 0;
     for(int j = 0; j < m; j++){
        numprime += primenum[num[i][j]];
     }
    if(numprime < max1){
         max1 = numprime;
     }
         //cout << i << " " << numprime << endl;
}
for(int i = 0; i < m; i++){
    int numprime = 0;
     for(int j = 0; j < n; j++){
        numprime += primenum[num[j][i]];
     }
    if(numprime < max1) max1 = numprime;
    //cout << i << " " << numprime << endl;
}
cout << max1 << endl;
return 0;
}