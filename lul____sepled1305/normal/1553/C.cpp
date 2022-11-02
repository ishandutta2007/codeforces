/**
    RIP IM 2020-2021
    Hi M 2019-2020, 2021-
**/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        int mini = 9;
        //Step 1: assume first team win
        int fi = 0, se = 0;
        for(int i=0;i<10;i++) {
            if(i%2 == 0) {
                if(s[i] != '0') fi++;
            }
            else {
                if(s[i] == '1') se++;
            }
            if(fi > se + (10-i)/2) {
                mini = min(mini,i);
                break;
            }
        }
        fi = 0, se = 0;
        for(int i=0;i<10;i++) {
            if(i%2 == 0) {
                if(s[i] == '1') fi++;
            }
            else {
                if(s[i] != '0') se++;
            }

            if(fi + (9-i)/2 < se) {
                mini = min(mini,i);
                break;
            }
        }
        cout<<mini+1<<endl;
    }
    return 0;
}