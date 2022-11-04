#include <iostream>
#include <string>

using namespace std;

int main(){
  int a,b,sum=0,res=0;

  cin >> a >> b;

  sum+=a;
  while(a>=b){
    int aux = a;
  	a = a / b;
	sum+=a;
	a += aux%b;
  }

  cout << sum;
  return 0;
}