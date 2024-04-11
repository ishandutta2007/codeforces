#include<iostream>
using namespace std;
string a,b,c;
main(){
    cin>>a>>b>>c;
    puts(a[0]==c[2]&&a[1]==c[1]&&a[2]==c[0]&&b[0]==b[2]?"YES":"NO");
}