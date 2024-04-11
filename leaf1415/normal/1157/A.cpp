#include <iostream>
#include <set>

using namespace std;

int n;
set<int> s;

int f(int n)
{
  n++;
  while(n%10==0) n/=10;
  return n;
}

int main(void)
{
  cin >> n;
  s.insert(n);
  while(1){
    n = f(n);
    if(s.count(n)) break;
    s.insert(n);
  }
  cout << s.size() << endl;
  return 0;
}