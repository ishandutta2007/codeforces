#include <iostream>
#include <vector>

using namespace std;

int n;
int a[200005];
int cnt[200005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cnt[a[i]]++;

  int ans = 0, sum = 0, l, ans_l, ans_r;
  bool flag = false;
  for(int i = 1; i <= 200003; i++){
    if(!flag){
      if(cnt[i]){
        l = i;
        flag = true;
        sum += cnt[i];
      }
    }
    else{
      sum += cnt[i];
      if(cnt[i] <= 1){
        if(ans < sum){
          ans = sum;
          ans_l = l;
          if(cnt[i] == 0) ans_r = i-1;
          else ans_r = i;
        }
        if(cnt[i] == 0) flag = false, sum = 0;
        if(cnt[i] == 1) flag = true, sum = cnt[i], l = i;
      }
    }
  }

  vector<int> vec;
  for(int i = ans_l; i <= ans_r; i++){
    vec.push_back(i), cnt[i]--;
  }
  for(int i = ans_r; i >= ans_l; i--){
    while(cnt[i]) vec.push_back(i), cnt[i]--;
  }
  cout << vec.size() << endl;
  for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  cout << endl;

  return 0;
}