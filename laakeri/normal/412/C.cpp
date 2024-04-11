#include <iostream>

using namespace std;

char asd[100001];

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int ma=0;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        ma=max(ma,(int)s.size());
        for (int ii=0;ii<s.size();ii++){
            if (s[ii]!='?'){
                if (asd[ii]==0){
                    asd[ii]=s[ii];
                }
                else if (asd[ii]=='?'){

                }
                else if (asd[ii]!=s[ii]){
                    asd[ii]='?';
                }
            }
        }
    }
    for (int i=0;i<ma;i++){
        if (asd[i]>0){
            cout <<asd[i];
        }
        else{
            cout <<'x';
        }
    }
}