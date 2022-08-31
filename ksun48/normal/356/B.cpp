#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
  return (a ==0)?b:gcd(b%a,a);
}
char x[1000010];
char y[1000010];
int main(){
  LL n, m;
  cin >> n >> m >> x >> y;
  LL len1 = strlen(x);
  LL len2 = strlen(y);
  LL g = gcd(len1,len2);
  LL ans = 0;
  for(LL i = 0; i < g; i++){
    LL freqx[26];
    LL freqy[26];
    for(int rr = 0; rr < 26; rr++){
      freqx[rr] = freqy[rr] = 0;
    }
    for(LL j = 0; j < len1/g; j++){
      freqx[x[i+j*g]-'a']++;
    }
    for(LL j = 0; j < len2/g; j++){
      freqy[y[i+j*g]-'a']++;
    }
    for(int rr = 0; rr < 26; rr++){
      ans += freqx[rr]*freqy[rr];
    }
  }
  LL num = len1/g*len2;
  cout << len1*n-ans*(n*g/len2) << endl;
}