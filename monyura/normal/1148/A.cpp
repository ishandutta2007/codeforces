#include <iostream>
#include <algorithm>

using namespace std;

int main(){
long long a,b,c;
cin>>a>>b>>c;
auto result = 2*c + 2*std::min(a,b) + (a!=b);
cout<<result<<endl;
return 0;
}