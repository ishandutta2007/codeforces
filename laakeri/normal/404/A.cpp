#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    char t;
    char t2;
    int v=1;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        if (i==0){
            t=a[0];
            t2=a[1];
        }
        if (t==t2){
            cout <<"NO"<<endl;
            return 0;
        }
        for (int ii=0;ii<n;ii++){
            if (i==ii||ii==n-i-1){
                if (a[ii]!=t){
                    v=0;
                }
            }
            else{
                if (a[ii]!=t2){
                    v=0;
                }
            }
        }
    }
    if (v){
        cout <<"YES"<<endl;
    }
    else{
        cout <<"NO"<<endl;
    }
}