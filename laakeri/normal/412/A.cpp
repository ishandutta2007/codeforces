#include <iostream>

using namespace std;

int used[102];

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if (n-k<k-1){
        for (int i=k;i<=n;i++){
            cout <<"PRINT "<<s[i-1]<<endl;
            used[i]=1;
            if (i<n){
                cout <<"RIGHT"<<endl;
            }
        }
        if (k>1){
            for (int i=n;i>0;i--){
                if (!used[i]){
                    cout <<"PRINT "<<s[i-1]<<endl;
                }
                if (i>1){
                    cout <<"LEFT"<<endl;
                }
            }
        }
    }
    else{
        for (int i=k;i>0;i--){
            cout <<"PRINT "<<s[i-1]<<endl;
            used[i]=1;
            if (i>1){
                cout <<"LEFT"<<endl;
            }
        }
        if (k<n){
            for (int i=1;i<=n;i++){
                if (!used[i]){
                    cout <<"PRINT "<<s[i-1]<<endl;
                }
                if (i<n){
                    cout <<"RIGHT"<<endl;
                }
            }
        }
    }
}