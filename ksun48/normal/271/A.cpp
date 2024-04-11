#include <iostream>
#include <string.h>
using namespace std;
int Abs(int n){
if (n < 0) return -n;
return n;
}
int main(){
int y;
cin >> y;
for(int i = y+1; i <= 9999; i++){
    int k = i;
    int freq[10];
    for(int j = 0; j < 10; j++) freq[j]=0;
    for(int j = 0; j < 4; j++){
        freq[k % 10]++;
        k = (k- k % 10)/10;
    }
    int n = 0;
    for(int j = 0; j < 10; j++){
        if( freq[j] > 0) n++;
    }
    if(n == 4){
        cout << i << endl;
        return 0;
    }
}
return 0;
}