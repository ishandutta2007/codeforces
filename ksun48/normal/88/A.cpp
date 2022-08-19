#include<iostream>
#include<cstdio>

using namespace std;
main (){
    char a[3][3];
    cin >> a[0] >> a[1] >> a[2];
    int num[3];
    for(int i = 0; i < 3; i++){
        if(a[i][1] == '#'){
            if(a[i][0] == 'C') num[i] = 1;
            if(a[i][0] == 'D') num[i] = 3;
            if(a[i][0] == 'F') num[i] = 6;
            if(a[i][0] == 'G') num[i] = 8;
        } else {
            if(a[i][0] == 'C') num[i] = 0;
            if(a[i][0] == 'D') num[i] = 2;
            if(a[i][0] == 'E') num[i] = 4;
            if(a[i][0] == 'F') num[i] = 5;
            if(a[i][0] == 'G') num[i] = 7;
            if(a[i][0] == 'A') num[i] = 9;
            if(a[i][0] == 'B') num[i] = 10;
            if(a[i][0] == 'H') num[i] = 11;
        }
    }
    for(int i = 0; i < 6; i++){
        int a[3];
        if(i == 0){
            a[0] = 0;
            a[1] = 1;
            a[2] = 2;
        } else if(i == 1){
            a[0] = 0;
            a[1] = 2;
            a[2] = 1;    
        }else if(i == 2){
            a[0] = 1;
            a[1] = 0;
            a[2] = 2;    
        } else if(i == 3){
            a[0] = 1;
            a[1] = 2;
            a[2] = 0;    
        } else if(i == 4){
            a[0] = 2;
            a[1] = 0;
            a[2] = 1;    
        } else if(i == 5){
            a[0] = 2;
            a[1] = 1;
            a[2] = 0;    
        }
        if((12+num[a[1]]-num[a[0]]) % 12 == 3 && (12+num[a[2]]-num[a[1]]) % 12 == 4){
            cout << "minor" << endl;
            return 0;
        } else if((12+num[a[1]]-num[a[0]]) % 12 == 4 && (12+num[a[2]]-num[a[1]]) % 12 == 3){
            cout << "major" << endl;        
            return 0;
        }
    }
     cout << "strange" << endl;
}