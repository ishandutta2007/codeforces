#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

#define wait system("pause")

const int oo = 0x3f3f3f3f;

typedef long long int64;



int main()
{         
          int n; cin >> n;
          vector< pair<int,int> > V(n);
          
          for (int i = 0; i < n; ++i){
              cin >> V[i].first;
              V[i].second = i;
              }
              
          sort(V.begin(), V.end());
          
          int cur = V[n - 1].first + 1;
          int pos = 0;
          
          for (int i = n - 1; i >= 0; --i)
          {
              if (V[i].first < cur)
              {
                 cur = V[i].first;
                 V[i].first = V[i].second;
                 pos = (n - i);
                 V[i].second = pos;
              }
              else{
                   V[i].first = V[i].second;
                   V[i].second = pos;
              }
          }
          
          sort(V.begin(), V.end());
          for (int i = 0; i < n; ++i)
              cout << V[i].second << " ";
          cout << endl;
          
          //wait;
          
          return 0;
}