#include <iostream>

using namespace std;

int main(){
    int f=0;
    int n1=0;
    int n2=0;
    int n=0;
    while (cin){
        string s;
        getline (cin,s);
        for (int i=0;i<s.size();i++){
            if (s[i]==' '){
                n++;
            }
            else if (s[i]-'0'>=0&&s[i]-'0'<=9){
                int asd=s[i]-'0';
                if (n==0){
                    n1*=10;
                    n1+=asd;
                }
                else{
                    n2*=10;
                    n2+=asd;
                }
            }
        }
    }
    cout <<n1+n2<<endl;
}