#include <bits/stdc++.h>
using namespace std;
void eat(){
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(a>=d&&b>=e&&c>=f&&a+c>=d+f+g&&b+c>=e+f+h&&a+b+c>=d+e+f+g+h)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)eat();
}