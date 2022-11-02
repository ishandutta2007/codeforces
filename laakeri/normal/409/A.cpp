#include <iostream>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int p1=0;
    int p2=0;
    for (int i=0;i<s1.size();i+=2){
        if (s1[i]=='['){
            if (s2[i]=='8'){
                p2++;
            }
            if (s2[i]=='('){
                p1++;
            }
        }
        if (s1[i]=='('){
            if (s2[i]=='8'){
                p1++;
            }
            if (s2[i]=='['){
                p2++;
            }
        }
        if (s1[i]=='8'){
            if (s2[i]=='['){
                p1++;
            }
            if (s2[i]=='('){
                p2++;
            }
        }
    }
    if (p1==p2){
        cout <<"TIE"<<endl;
    }
    else if (p1>p2){
        cout <<"TEAM 1 WINS"<<endl;
    }
    else {
        cout <<"TEAM 2 WINS"<<endl;
    }
}