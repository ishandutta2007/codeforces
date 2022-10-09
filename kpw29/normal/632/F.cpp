    #include "bits/stdc++.h"
    using namespace std;
    int grid[2505][2505];
    vector<pair<int, pair<int,int>>>nums;
    bitset<2505>masks[2505];
    int main(){
     
      int n;
      scanf("%d", &n);
     
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          scanf("%d", &grid[i][j]);
          if(grid[i][i] || (i > j && grid[i][j] != grid[j][i]))
            return puts("NOT MAGIC");
          nums.push_back(make_pair(grid[i][j],make_pair(i,j)));
        }
      }
      sort(nums.begin(),nums.end());
      for(int i = 0; i < n * n; ){
        int last = i;
        while(last < n * n && nums[last].first == nums[i].first){
     
          if( (masks[nums[last].second.first] & masks[nums[last].second.second]).any() )
            return puts("NOT MAGIC");
     
          last++;
        }
     
        for(int j = i; j < last; j++){
          masks[nums[j].second.first].set(nums[j].second.second);
        }
     
     
        i = last;
      }
     
      puts("MAGIC");
     
      return 0;
    }