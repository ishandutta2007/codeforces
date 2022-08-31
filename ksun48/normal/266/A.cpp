#include <iostream>
#include <string.h>
using namespace std;
int main(){
int n;
cin >> n;
char s[n+1];
cin >> s;
int a = 0;
for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]) a++;

}
cout << a << endl;


return 0;
}