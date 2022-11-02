#include <iostream>
#include <string>

using namespace std;

int m[303];

int main(){
    int n;
    int r=1;
    int i;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>m[i];
    }
    int lm;
    string v;
    int f;
    for (i=1;i<=n;i++){
        if (m[i]!=0){
            lm=i;
            break;
        }
    }
    while (true) {
        if (m[r]>0){
            m[r]--;
            v+="P";
            if (m[r]==0&&lm==r){
                f=0;
                for (i=lm;i<=n;i++){
                    if (m[i]!=0){
                        f=1;
                        lm=i;
                        break;
                    }
                }
                if (f==0) break;
            }
        }
        if (lm<r||r==n){
            v+="L";
            r--;
        }
        else {
            v+="R";
            r++;
        }
    }
    cout << v << endl;
}