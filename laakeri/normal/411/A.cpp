#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int c5=s.size()>=5;
    int ll=0;
    int sl=0;
    int dg=0;
    for (int i=0;i<s.size();i++){
        if (s[i]>='A'&&s[i]<='Z') ll=1;
        if (s[i]>='a'&&s[i]<='z') sl=1;
        if (s[i]>='0'&&s[i]<='9') dg=1;
    }
    if ((c5&ll)&(sl&dg)) cout <<"Correct"<<endl;
    else cout <<"Too weak"<<endl;
}