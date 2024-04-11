#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str;
int main(){
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++)
        if(str[i] == '1') cnt ++ ;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '1') continue;
        else if(str[i] == '2' && cnt){
            for(int j = 0; j < cnt; j++) printf("1"); cnt = 0; 
        }
        printf("%c", str[i]);
    }
    if(cnt)for(int j = 0; j < cnt; j++) printf("1"); 
    
    return 0;
}