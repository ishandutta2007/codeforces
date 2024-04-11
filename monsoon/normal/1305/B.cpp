#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
char s[N];
int n;
vector<int> a,b;

int main() {
  scanf("%s",s);
  n = strlen(s);
  int i=0,j=n-1;
  while (i < j) {
    while (i < j && s[i]==')') ++i;
    while (i < j && s[j]=='(') --j;
    if (i < j) {
      a.push_back(i);
      b.push_back(j);
      ++i; --j;
    }
  }
  if (a.empty()) {
    puts("0");
  } else {
    printf("1\n%d\n",2*(int)a.size());
    for (int x : a) printf("%d ",x+1);
    reverse(b.begin(),b.end());
    for (int x : b) printf("%d ",x+1);
    printf("\n");
  }
}