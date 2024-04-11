#include <iostream>

using namespace std;

int ny[101];
int nx[101];
int hy[101];
int hx[101];

int ma[101][101];
int rma[101][101];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cin>>ma[i][ii];
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (ma[i][ii]==0){
                ny[i]=1;
                nx[ii]=1;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if ((!ny[i])&&(!nx[ii])){
                rma[i][ii]=1;
                hx[ii]=1;
                hy[i]=1;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            if (hy[i]||hx[ii]){
                if (ma[i][ii]==0){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else{
                if (ma[i][ii]==1){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cout<<rma[i][ii]<<" ";
        }
        cout<<'\n';
    }
}