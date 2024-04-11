#include <iostream>
#include <string.h>
using namespace std;
int main(){
int n, t;
cin >> n >> t;
char s[n+1];
cin >> s;
int a = 0;
for(int k = 0; k < t; k++){
for(int i = 0; i < n-1; i++){
    if(s[i] == 'B' && s[i+1] == 'G'){
        s[i] = 'G'; s[i+1] = 'B';
        i++;
    }

}
}
for(int i = 0; i < n; i++){
cout << s[i];
}
cout << endl;
return 0;
}