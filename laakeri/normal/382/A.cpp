#include <iostream>

using namespace std;

int main() {
    string s;
    string s2;
    cin>>s;
    int i;
    int l;
    int r;
    for (i=0;i<s.size();i++){
        if (s[i]=='|'){
            l=i;
            r=s.size()-i-1;
        }
    }
    cin>>s2;
    i=0;
    while (l>r&&i<s2.size()){
        s=s+s2[i];
        i++;
        r++;
    }
    while (l<r&&i<s2.size()){
        s=s2[i]+s;
        i++;
        l++;
    }
    while (i<s2.size()){
        if (i%2==0){
            s=s2[i]+s;
            l++;
        }
        else {
            s=s+s2[i];
            r++;
        }
        i++;
    }
    if (l==r) cout <<s<<endl;
    else cout <<"Impossible"<<endl;
}