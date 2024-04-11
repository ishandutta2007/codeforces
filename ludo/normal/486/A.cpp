#include <iostream>

using namespace std;


int main(){
  long long n;
  cin>>n;
  if (n&1)
    cout<<(-1-(n/2))<<endl;
  else
    cout<<(n/2)<<endl;
  return 0;
}