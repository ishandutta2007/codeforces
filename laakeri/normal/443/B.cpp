#include <iostream>

using namespace std;

string s;
int k;

int is(int n, char c){
    if (n<s.size()){
        return s[n]==c;
    }
    else{
        return 1;
    }
}

int main(){
    cin>>s;
    cin>>k;
    int m=0;
    for (int p=0;p<s.size();p++){
        for (int n=1;n<=(s.size()+k-p)/2;n++){
            int f=0;
            for (int i=0;i<n;i++){
                if (!is(p+i+n,s[p+i])){
                    f=1;
                    break;
                }
            }
            if (f==0){
                m=max(m,n);
            }
        }
    }
    cout<<m*2<<endl;
}