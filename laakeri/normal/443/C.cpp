#include <iostream>

using namespace std;

int ctn[300];

int cn[200];
int cc[200];

int mi=10;

int n;

void reveal (int rn, int rc, int m, int k){
    if (k>6) return;
    int ok=1;
    for (int i=0;i<n;i++){
        for (int ii=i+1;ii<n;ii++){
            if (cn[i]!=cn[ii]||cc[i]!=cc[ii]){
                ok=0;
                if (cn[i]!=cn[ii]){
                    if ((rn&(1<<cn[i]))||(rn&(1<<cn[ii]))){
                        ok=1;
                    }
                }
                if (cc[i]!=cc[ii]){
                    if ((rc&(1<<cc[i]))||(rc&(1<<cc[ii]))){
                        ok=1;
                    }
                }
            }
            if (ok==0){
                break;
            }
        }
        if (ok==0){
            break;
        }
    }
    if (ok==1){
        mi=min(mi,m);
        return;
    }
    reveal(rn|(1<<k),rc,m+1,k+1);
    reveal(rn,rc|(1<<k),m+1,k+1);
    reveal(rn|(1<<k),rc|(1<<k),m+2,k+1);
    reveal(rn,rc,m,k+1);
}

int main(){
    ctn['R']=1;
    ctn['G']=2;
    ctn['B']=3;
    ctn['Y']=4;
    ctn['W']=5;
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        cc[i]=ctn[s[0]];
        cn[i]=s[1]-'0';
    }
    reveal(0,0,0,1);
    cout<<mi<<endl;
}