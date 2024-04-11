#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]>'4'){
            int a=9-(s[i]-'0');
            if (i>0){
                s[i]='0'+a;
            }
            else if(a>0){
                s[i]='0'+a;
            }
        }
    }
    cout<<s<<endl;
}