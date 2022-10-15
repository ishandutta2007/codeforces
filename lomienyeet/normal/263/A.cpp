#include <bits/stdc++.h>
using namespace std;
int main(){
    int bruh[5][5];
    int temp,temp2;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>bruh[i][j];
            if(bruh[i][j]==1){
                temp=i;
                temp2=j;
                break;
            }
        }
    }
    cout<<abs(temp-2)+abs(temp2-2)<<"\n";
}