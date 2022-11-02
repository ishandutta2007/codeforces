#include <iostream>

using namespace std;

int cs[30];
int ct[30];

int main(){
    string s,t;
    cin>>s>>t;
    if (s.size()>=t.size()){
        int ii=0;
        for (int i=0;i<t.size();i++){
            while (s[ii]!=t[i]){
                ii++;
                if (ii>=s.size()) break;
            }
            if (ii>=s.size()) break;
            if (i<t.size()-1) ii++;
        }
        if (ii<s.size()){
            cout<<"automaton"<<endl;
            return 0;
        }
    }
    for (char c:s){
        cs[c-'a']++;
    }
    for (char c:t){
        ct[c-'a']++;
    }
    int f=0;
    int b=0;
    for (int i=0;i<30;i++){
        if (ct[i]>cs[i]) f=1;
        if (ct[i]!=cs[i]) b=1;
    }
    if (!f){
        if (b) cout<<"both"<<endl;
        else cout<<"array"<<endl;
        return 0;
    }
    cout <<"need tree"<<endl;
}