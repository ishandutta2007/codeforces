//In the name of Allah
#include <iostream>
using namespace std;
int main() { 
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int s = a + b + c + d + e;
    cout << (s%5==0&&s!=0?s/5:-1) << endl;
}