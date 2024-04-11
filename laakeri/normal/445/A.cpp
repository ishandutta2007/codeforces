#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int ii=0;ii<m;ii++){
            int c=(ii+i)%2;
            if (s[ii]=='.'){
                if (c==0){
                    s[ii]='W';
                }
                else{
                    s[ii]='B';
                }
            }
        }
        cout <<s<<endl;
    }
}