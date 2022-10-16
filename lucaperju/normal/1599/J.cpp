#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int v[N];
const int VMAX = 2e6 + 5;
vector<pair<int, int>> sums[VMAX];
int ans[N];
bool viz[N];

map<long long, int> frv[31];

  vector<int> va, vb;
int main()
{
  //freopen(".in","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int n;
  cin>>n;
  int nrp = 0, nri = 0;
  for(int i = 1; i<=n; i++){
    cin>>v[i];
    if(v[i]%2 == 0)
      nrp++;
    else
      nri++;
  }
  sort(v +1, v + n+ 1);

  for(int i =1 ; i<=n; i++){
    if(v[i] == v[i + 1]){
      // cel putin 2 egale
      cout<<"YES\n";
      cout<<"0 ";
      for(int j = 1; j <= n; j++){
        if(i == j)
          continue;
        cout<<v[j]<<" ";
      }
      return 0;
    }
  }
  if(n == 2){
    cout<<"NO\n";
    return 0;
  }
  if(nri < n){
    if(nrp == 2 && nri == 1){
      cout<<"NO\n";
      return 0;
    }
    int choose = 1;
    while(v[choose]%2 == 1)
      choose++;
    //choose e par
    int choose1 =1, choose2 = 1;
    if(nrp < 3){
      while(v[choose1]%2 == 0 || choose1 == choose)
        choose1++;
      //choose1 e impar
      while(v[choose2]%2 == 0 || choose2 == choose || choose2 == choose1)
        choose2++;
      //choose 2 e impar
    }
    else{
      while(v[choose1]%2 == 1 || choose1 == choose)
        choose1++;
      //choose1 e par
      while(v[choose2]%2 == 1 || choose2 == choose || choose2 == choose1)
        choose2++;
      //choose 2 e par
    }
    assert((v[choose1] + v[choose2] - v[choose] )%2 == 0);
    int x = (v[choose1] + v[choose2] - v[choose] )/ 2;
    cout<<"YES\n";
    cout<<x<<" ";
    for(int i =1 ; i<=n; i++){
      if(i == choose)
        continue;
      cout<<v[i] - x<<" ";
    }
    return 0;
  }
  if(n == 3){
    cout<<"NO\n";
    return 0;
  }
  int mask = 0;
  int mask1 = 0;
  while(mask <= (1LL << (min(n, 30)))){
    mask++;
    long long csum = 0, sz = 0;
    for(int b = 30; b >= 0; b--){
      if(mask &(1<<b))
        csum += v[b + 1], sz++;
    }
    if(frv[sz][csum]){
      mask1 = frv[sz][csum];
      break;
    }
    frv[sz][csum] = mask;
  }
  if(mask1 == 0){
    cout<<"NO\n";
    return 0;
  }
  int aux = mask1 & mask;
  mask1 ^= aux;
  mask ^= aux;
  for(int b = 30; b>=0; b--){
    if(mask & (1<<b))
      va.push_back(b + 1);
  }
  for(int b = 30; b>=0; b--){
    if(mask1 & (1<<b))
      vb.push_back(b + 1);
  }
  ans[1] = 0;
  int k =1;
  for(int i = 0; i <va.size(); i++){
    viz[va[i]] = viz[vb[i]] = true;
    k++;
    ans[k] = v[va[i]] - ans[k - 1];
    if(i < va.size()-1)
      k++,ans[k] = v[vb[i]] - ans[k - 1];
  }
  for(int i =1 ; i<=n; i++){
    if(viz[i] == true)
      continue;
    ans[++k] = v[i] - ans[1];
  }
  cout<<"YES\n";
  for(int i =1 ;i<=n; i++)
    cout<<ans[i]<<" ";
  return 0;
}