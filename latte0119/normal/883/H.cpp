#include<bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  string S;

  cin >> N;
  cin >> S;

  vector< int > div;
  for(int i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      div.push_back(i);
      if(i * i != N) div.push_back(N / i);
    }
  }
  sort(begin(div), end(div));
  reverse(begin(div), end(div));

  int beet[128] = {}, buff[128] = {};
  int all = 0;
  for(auto &c : S) {
    beet[c]++, buff[c]++;
  }
  for(int i =0; i < 128; i++) all += beet[i] / 2;

  for(int length : div) {
    int need = N / length;
    if(1LL * need * (length / 2) > all) continue;

    vector< string > ans(need), add(need);
    int ptr = 0;
    for(int j = 0; j < length / 2; j++) {
      for(int i = 0; i < need; i++) {
        while(ptr < 128 && beet[ptr] <= 1) ++ptr;
        if(ptr == 128) goto ng;
        beet[ptr] -= 2;
        ans[i] += (char) (ptr);
      }
    }

    if(length % 2 == 1) {
      ptr =0;
      for(int i = 0; i < need; i++) {
        while(ptr < 128 && beet[ptr] == 0) ++ptr;
        if(ptr == 128) goto ng;
        beet[ptr]--;
        add[i] = (char) (ptr);
      }
    }

    cout << need << endl;
    for(int i = 0; i < need; i++) {
      string rev = ans[i];
      reverse(begin(rev), end(rev));
      cout << rev << add[i] << ans[i] << " ";
    }
    cout << endl;
    return (0);

    ng:;
    for(int i = 0; i < 128; i++) beet[i] = buff[i];
  }

}