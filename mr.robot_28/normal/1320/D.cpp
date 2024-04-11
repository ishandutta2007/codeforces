#include <bits/stdc++.h>
#define X first
#define Y second
#define inf 100000000000000000
#define ll long long

using namespace std;

ll n, q, prime, temp, temp1, temp2, pow3[200009], zeros[200009], hash3[200009], odd[200009], inv_odd[200009];
string s;

pair<int,int> get_hash3(int l, int r, int p){
  int temp_hash3 = 0;

  if(odd[l-1] == 1 && min(inv_odd[l], 1ll*(r-l+1))%2 == 1)temp_hash3 = (((hash3[r] - 2*hash3[l] + hash3[l-1] + 2*prime) % prime) * pow3[p]) % prime;
  else temp_hash3 = (((hash3[r] - hash3[l-1] + prime) % prime) * pow3[p]) % prime;

  return(make_pair(temp_hash3, zeros[r] - zeros[l-1]));
}


int main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
pow3[0] = 1;
prime = 1000000007;
for(int i = 1; i <= 200001; i++)
    pow3[i] = (pow3[i - 1] * 3) % prime;

  cin >> n >> s;


  for(int i = 1; i <= n; i++){
    zeros[i] = zeros[i-1] + (s[i-1] == '0');
  }
  for(int i = n; i >=1; i--){
    if(s[i-1] == '1')inv_odd[i] = inv_odd[i+1] + 1;
    else inv_odd[i] = 0;
  }

  temp = 0;
  for(int i = 1; i <= n; i++){
    if(s[i-1] == '0')hash3[i] = hash3[i - 1];
    if(s[i-1] == '1'){
        if(i-1 == 0 || s[i-2] == '0'){
                hash3[i] = (hash3[i-1] + pow3[zeros[i]]) % prime;
                odd[i] = 1;
        }
        else{
            hash3[i] = hash3[i-2];
            odd[i] = odd[i-2];
        }
    }
  }

  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> temp1 >> temp2 >> temp;
    if(get_hash3(temp1, temp1 + temp - 1, zeros[temp2-1]) == get_hash3(temp2 , temp2 + temp - 1,zeros[temp1-1]))cout << "yes" << '\n';
    else cout << "no" << '\n';
  }
}