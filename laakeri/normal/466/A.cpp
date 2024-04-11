#include <iostream>

using namespace std;

int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int v1=(n/m)*b+(n%m)*a;
    int v2=(n/m+1)*b;
    int v3=n*a;
    cout<<min(v1, min(v2, v3))<<endl;
}