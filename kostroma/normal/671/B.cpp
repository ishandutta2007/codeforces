#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

double distance(double fx, double fy, double sx, double sy) {
  return sqrt((fx-sx)*(fx-sx)+(fy-sy)*(fy-sy));
}

void solve(int n) {
  long long k;
  cin >> k;
  vector<int> data(n);
  long long sum = 0;
  for ( int i = 0; i < n;++i ) {
    scanf("%d", &data[i]);
    sum += data[i];
  }
  double avg = double(sum) / n;
  long long low = sum / n;
  long long up = (sum + n - 1) / n;
  sort(data.begin(), data.end());
  if (k == 0 ) {
    cout << data[data.size()-1] - data[0];
    return;
  }
  int last_lower = -1;
  int first_upper = -1;
  for ( int i = 0; i < n; ++i ) {
    if ( data[i] < low) {
      last_lower = std::max(last_lower, i);
    }
  }
  for ( int i = 0; i < n; ++i ) {
    if ( data[n-1-i] > up) {
      first_upper = std::max(first_upper, i);
    }
  }
  vector<long long> low_sum;
  low_sum.push_back(0);
  for ( int i = 1; i <= last_lower; ++i ) {
    low_sum.push_back(low_sum.back() + (data[i] - data[i-1]) * i);
  }
  if ( last_lower >= 0) {
    low_sum.push_back(low_sum.back() + (low - data[last_lower]) * (last_lower + 1));
  }
  vector<long long> up_sum;
  up_sum.push_back(0);
  for ( int i = 1; i <= first_upper; ++i ) {
    up_sum.push_back(up_sum.back() + (data[n-i] - data[n-1-i]) * i);
  }
  if ( first_upper >= 0 ) {
    up_sum.push_back(up_sum.back() + (data[n - 1 - first_upper] - up) * (first_upper + 1));
  }

  auto low_it = lower_bound(low_sum.begin(), low_sum.end(), k);
  auto up_it = lower_bound(up_sum.begin(), up_sum.end(), k);
  auto low_ind = low_it - low_sum.begin();
  auto up_ind = up_it - up_sum.begin();

  if ( up_ind >= up_sum.size() && low_ind >= low_sum.size()) {
    cout << up - low << endl;
    return;
  }

  long long low_rest = k - low_sum[low_ind-1];
  long long up_rest = k - up_sum[up_ind-1];
  long long low_bound = data[low_ind-1] + low_rest / low_ind;
  long long up_bound = data[n-up_ind] - up_rest / up_ind;
  cout << up_bound - low_bound;
  return;

  for ( int i = 0; i < low_sum.size(); ++i ){
    cout << low_sum[i] << ' ';
  }
  cout << endl;
  cout << low_ind << endl;
  for ( int i = 0; i < up_sum.size(); ++i ){
    cout << up_sum[i] << ' ';
  }
  cout << endl;
  cout << up_ind << endl;
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif
  int n;
  while(scanf("%d",&n)!=EOF){
    solve(n);
  }
  return 0;
}