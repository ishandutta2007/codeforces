#include<bits/stdc++.h>
using namespace std;


int main() {
  int ans=0;
  int sign=+1;
  int val=0;
  string s;
  cin>>s;

  for(char c:s) {
    if(c=='-' || c=='+') {
      ans+=sign*val;
      if(c=='-')sign=-1;else sign=+1;
      val=0;
    }
    val = 10*val+(int)(c-'0');
  }

  ans+=sign*val;

  cout<<ans;
  return 0;
}