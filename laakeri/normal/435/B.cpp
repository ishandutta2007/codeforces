#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ii=0;
    while (k>0&&ii<s.size()-1){
        int m=s[ii];
        int mp=-1;
        for (int i=ii+1;i<=ii+k&&i<s.size();i++){
            if (s[i]>m){
                m=s[i];
                mp=i;
            }
        }
        if (mp>-1){
            for (int i=mp-1;i>=ii;i--){
                swap(s[i],s[i+1]);
                k--;
            }
        }
        else{
            ii++;
        }
    }
    cout <<s<<endl;
}