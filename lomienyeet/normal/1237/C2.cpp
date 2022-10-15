#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int32_t main(){
  // learning a new indentation
  int n;
  std::cin >> n;
  std::map<std::pair<int, int>, std::vector<std::pair<int, int> > > mp;
  for (int i = 0, a, b, c; i < n; i++){
    std::cin >> a >> b >> c;
    mp[{a, b}].push_back({c, i + 1});
  }
  std::map<int, std::vector<std::pair<int, int> > > mp2;
  for (auto i : mp){
    std::sort(i.second.begin(), i.second.end());
    for (int j = 1; j < i.second.size(); j += 2){
      std::cout << i.second[j].second << " " << i.second[j-1].second << "\n";
    }
    if(i.second.size() & 1){
      mp2[i.first.first].push_back({i.first.second, i.second.back().second});
    }
  }
  std::vector<int> v;
  for (auto i : mp2){
    sort(i.second.begin(), i.second.end());
    for (int j = 1; j < i.second.size(); j += 2){
      std::cout << i.second[j].second << " " << i.second[j-1].second << "\n";
    }
    if(i.second.size() & 1){
      v.push_back(i.second.back().second);
    }
  }
  for (int i = 0; i + 1 < v.size(); i += 2){
    std::cout << v[i] << " " << v[i+1] << "\n";
  }
  return 0;
}