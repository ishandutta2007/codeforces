#include <iostream>
#include <vector>

using namespace std;


int main(){
     long long  n,m,a,x,y;
     cin>>n>>m>>a;
     x=(n+a-1)/a;
     y=(m+a-1)/a;
     cout<<x*y<<endl;

 return 0;
}