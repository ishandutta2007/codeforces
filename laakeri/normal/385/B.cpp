#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    int v=0;
    int i;
    int ss=s.size();
    int m=0;
    for (i=0;i<ss-3;i++){
        if (s.substr(i,4)=="bear"){
            for (;m<=i;m++){
                v+=ss-3-i;
            }
        }
    }
    cout <<v<<endl;
}