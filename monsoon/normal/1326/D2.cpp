#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100000;
int _,n;
char s[N],z[N];


struct manacher {
  int n;
  vector<int> r[2];  // even (len 2*r), odd (len 2*r-1)

  template<class RandomAccessIterator>
  manacher(RandomAccessIterator first, RandomAccessIterator last) {
    n = last - first;
    REP(e,2) {
      vector<int>& R = r[e];
      R.resize(n);
      int j = R[0] = 0;
      REP(i,n) {
        int r = max(0, min(R[2*j-i], j+R[j]-i));
        if (i+r >= j+R[j])
          for (j = i; i-r-!e >= 0 && i+r < n && *(first+i-r-!e) == *(first+i+r); ++r) ;
        R[i] = r;
      }
    }
  }

  bool is_palindrome(int i, int j) const {
    assert(0 <= i && i <= j && j <= n);
    return r[(j-i)%2][(i+j)/2] >= (j-i+1)/2;
  }
};


int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%s",s);
    n = strlen(s);
    manacher mana(s,s+n);

    int j = 0, ans = 0;
    while (2*j<n-1 && s[j] == s[n-1-j]) ++j;
    z[0] = 0;
    for (int len=n-2*j; len>=0; --len) {
      int pos = -1;
      if (mana.is_palindrome(j,j+len)) pos = j;
      else if (mana.is_palindrome(n-j-len,n-j)) pos = n-j-len;
      if (pos != -1) {
        strncpy(z,s,j); z[j] = 0;
        strncpy(z+j,s+pos,len); z[j+len] = 0;
        strcpy(z+j+len,s+n-j);
        break;
      }
    }
    puts(z);
  }
}