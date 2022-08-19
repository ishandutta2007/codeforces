#include <iostream>
#include <cstring>
using namespace std;
char str[110000];
int stuff[110000];
int num = 0;
int main() {
    cin >> str;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == '+'){
            if(num>0 && stuff[num-1] == 1){
                num--;
            } else {
                stuff[num] = 1;
                num++;
            }
        } else if(str[i] == '-'){
            if(num>0 && stuff[num-1] == 2){
                num--;
            } else {
                stuff[num] = 2;
                num++;
            }           
        }
    }
    if(num == 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    return 0;
}