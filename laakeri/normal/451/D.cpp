#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    string s;
    cin>>s;
    ll bo=0;
    ll be=0;
    ll ao=0;
    ll ae=0;
    ll o=0;
    ll e=0;
    for (int i=0;i<s.size();i++){
        o++;

        if (i%2){
            if (s[i]=='b'){
                o+=bo;
                e+=be;
                bo++;
            }
            else{
                o+=ao;
                e+=ae;
                ao++;
            }
        }
        else{
            if (s[i]=='b'){
                e+=bo;
                o+=be;
                be++;
            }
            else{
                e+=ao;
                o+=ae;
                ae++;
            }
        }
    }
    cout<<e<<" "<<o<<endl;
}