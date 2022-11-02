#include <iostream>

using namespace std;

string ns[10]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<8;i++){
        if (ns[i].size()==s.size()){
            int f=0;
            for (int ii=0;ii<ns[i].size();ii++){
                if (s[ii]!='.'){
                    if (s[ii]!=ns[i][ii]){
                        f=1;
                    }
                }
            }
            if (!f){
                cout<<ns[i]<<endl;
                return 0;
            }
        }
    }
}