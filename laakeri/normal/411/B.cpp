#include <iostream>

using namespace std;

int lc[101];
int lm[101];

int asd[101][101];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cin>>asd[i][ii];
        }
    }
    for (int ii=0;ii<m;ii++){
        for (int i=0;i<n;i++){
            if (!lc[i]){
                if (asd[i][ii]){
                    if (lm[asd[i][ii]]){
                        lc[i]=ii+1;
                    }
                    else{
                        for (int iii=0;iii<n;iii++){
                            if (!lc[iii]){
                                if (asd[iii][ii]==asd[i][ii]&&iii!=i){
                                    lc[iii]=ii+1;
                                    lc[i]=ii+1;
                                    lm[asd[i][ii]]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        cout <<lc[i]<<endl;
    }
}