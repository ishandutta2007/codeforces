#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    if (s.size()<=1){
        int lol=s[0]-'0';
        int v=0;
        for (int i=1;i<5;i++){
            int a=1;
            for (int ii=0;ii<lol;ii++){
                a*=i;
            }
            v+=a;
        }
        v%=5;
        cout<<v<<endl;
        return 0;
    }
    int m4=0;
    int m2=0;
    for (int i=0;i<s.size();i++){
        m4*=10;
        m2*=10;
        m4+=s[i]-'0';
        m2+=s[i]-'0';
        m4%=4;
        m2%=2;
    }
    int v=1;
    if (m4==0) v+=2;
    if (m4==1) v+=5;
    if (m4==2) v+=8;
    if (m4==3) v+=5;
    if (m2==0) v+=1;
    if (m2==1) v+=4;
    v%=5;
    cout<<v<<endl;
}