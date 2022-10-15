#include <iostream>
#include <vector>
using namespace std;
const int max_n = 160000;
inline void print(const vector<vector<int>> &vvi, int c){
    for (int i = 1; i < vvi[c].size(); ++i){
        if (vvi[c][i] >= max_n){
            print(vvi, vvi[c][i] - max_n);
        } else{
            cout << vvi[c][i] << " ";
        }
    }
}

inline int check(const vector<vector<int>> &vvi, int c){
    if (vvi[c][0] == -1){
        return c;
    } else{
        c = vvi[c][0];
        while(true){
            if (vvi[c - max_n][0] == -1){
                return c - max_n;
            } else {
                c = vvi[c - max_n][0];
            }
        }
    }
    return c;
}
int main(){
  int n; 
  cin >> n;
  int cell[n + 1];
  for (int i = 0; i <= n; ++i){
      cell[i] = -1;
  }
  vector<vector<int>> kitten(0);
  int c;
  for (int i = 0; i < n - 1; ++i){
      int x, y;
      cin >> x >> y;
      if (cell[x] == -1 && cell[y] == -1){
          c = kitten.size();
          kitten.push_back(vector<int>(3));
          kitten[c][0] = -1;
          kitten[c][1] = x;
          kitten[c][2] = y;
          cell[x] = c;
          cell[y] = c;
      } else if (cell[x] != -1 && cell[y] != -1){
          c = check(kitten, cell[x]);
          kitten[c].push_back(check(kitten, cell[y]) + max_n);
          kitten[check(kitten, cell[y])][0] = c + max_n;
          cell[y] = c;
      } else if (cell[x] != -1){
          c = check(kitten, cell[x]);
          kitten[c].push_back(y);
          cell[y] = c;
      } else if (cell[y] != -1){
          c = check(kitten, cell[y]);
          kitten[c].push_back(x);
          cell[x] = c;
      }
  }
  int begin;
  for (int i = 0; i < kitten.size(); ++i){
      if (kitten[i][0] == -1){
          begin = i;
      }
  }
  print(kitten, begin);
}