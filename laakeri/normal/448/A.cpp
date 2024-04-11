#include <iostream>

using namespace std;

int main(){
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int b1,b2,b3;
    cin>>b1>>b2>>b3;
    int n;
    cin>>n;
    int a=a1+a2+a3;
    int b=b1+b2+b3;
    int ne=a/5;
    if (a%5) ne++;
    ne+=b/10;
    if (b%10) ne++;
    if (ne>n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}