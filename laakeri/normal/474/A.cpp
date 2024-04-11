#include <iostream>

using namespace std;

string s[3];

int main(){
    s[0]="qwertyuiop";
    s[1]="asdfghjkl;";
    s[2]="zxcvbnm,./";
    char lol;
    cin>>lol;
    string ss;
    cin>>ss;
    for (int iii=0;iii<ss.size();iii++){
        for (int i=0;i<3;i++){
            for (int ii=0;ii<s[i].size();ii++){
                if (s[i][ii]==ss[iii]){
                    if (lol=='R'){
                        cout<<s[i][ii-1];
                    }
                    else{
                        cout<<s[i][ii+1];
                    }
                }
            }
        }
    }
}